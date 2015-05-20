var pointArray = new Array(); //存放直线
var beginPoint = new Object(); //存放矩形开始点
var endPoint = new Object(); //存放矩形结束点
var status = 0; //判断点击次数
var LinePointBegin = new Object(); //记录处理前的直线的两点坐标
var LinePointEnd = new Object(); //记录处理后的直线的两点坐标


//定义矩形上下左右编码
var LEFT = 1;
var RIGHT = 2;
var BOTTOM = 4;
var TOP = 8;

function filling(canvasId) {
	var count = 0;
	var c = document.getElementById(canvasId);
	var ctx = c.getContext("2d");
	var hx = c.getBoundingClientRect().left; // 元素左边距离页面左边的距离
	var hy = c.getBoundingClientRect().top; // 元素上边距离页面上边的距离
	var x0 = 0;
	var x1 = 0;
	var y0 = 0;
	var y1 = 0;
	$(document).click(function() {
		var xt = event.clientX;
		var yt = event.clientY;
		if (xt >= c.getBoundingClientRect().left && xt <= c.getBoundingClientRect().right && yt >= c.getBoundingClientRect().top && yt <= c.getBoundingClientRect().bottom) {
			if (count == 0) {
				//点击起始位置
				beginPoint.x = xt - hx;
				beginPoint.y = yt - hy;
				$("#sx").text(beginPoint.x);
				$("#sy").text(beginPoint.y);
				count = 1;
			} else if (count == 1) {
				//点击结束位置
				count = 2;
				endPoint.x = xt - hx;
				endPoint.Y = yt - hy;
				$("#ex").text(endPoint.x);
				$("#ey").text(endPoint.y);
				ctx.clearRect(0, 0, 700, 400);
				ctx.strokeStyle = "#000000";
				drawCubiod(beginPoint.x, beginPoint.y, endPoint.x, endPoint.y, ctx);
				ctx.stroke();
			} else if (count == 2) {
				if (status == 0) {
					x0 = xt - hx;
					y0 = yt - hy;
					$("#sx").text(x0);
					$("#sy").text(y0);
					status = 1;
					console.log("画线开始点击：X：" + x0 + "Y:" + y0);
				} else {
					status = 0;
					x1 = xt - hx;
					y1 = yt - hy;
					var t = pointArray.length;
					console.log("数组长度" + t);
					pointArray[t] = [x0, y0, x1, y1];
					console.log("画线结束点击：X：" + x1 + "Y:" + y1);
					console.log('点坐标：' + pointArray[t]);
					//处理画出来的直线
					Line_Clipping(x0, y0, x1, y1, beginPoint.x, beginPoint.y, endPoint.x, endPoint.y);
					pointArray[t] = [LinePointEnd.x1, LinePointEnd.y1, LinePointEnd.x2, LinePointEnd.y2];
					if (x0 != 0) {
						ctx.clearRect(0, 0, 700, 400);
						ctx.strokeStyle = "#000000";
						drawCubiod(beginPoint.x, beginPoint.y, endPoint.x, endPoint.y, ctx);
						DDAline(LinePointEnd.x1, LinePointEnd.y1, LinePointEnd.x2, LinePointEnd.y2, ctx);
					}
					for (var i = 0; i < pointArray.length; i++) {
						DDAline(pointArray[i][0], pointArray[i][1], pointArray[i][2], pointArray[i][3], ctx);
					}
				}
			}
		}
	});


	//鼠标移动获取坐标
	$(document).mousemove(function() {
		if (count == 1) {
			endPoint.x = event.clientX - hx;
			endPoint.y = event.clientY - hy;
			$("#sx").text(beginPoint.x);
			$("#sy").text(beginPoint.x);
			ctx.clearRect(0, 0, 700, 400);
			ctx.strokeStyle = "#000000";
			drawCubiod(beginPoint.x, beginPoint.y, endPoint.x, endPoint.y, ctx);
			ctx.stroke();
		} else if (count == 2 && status == 1) {
			x1 = event.clientX - hx;
			y1 = event.clientY - hy;
			if (status == 1) {
				$("#ex").text(x1);
				$("#ey").text(y1);
			}
			if (x0 != 0) {
				ctx.clearRect(0, 0, 700, 400);
				ctx.strokeStyle = "#000000";
				drawCubiod(beginPoint.x, beginPoint.y, endPoint.x, endPoint.y, ctx);
				DDAline(x0, y0, x1, y1, ctx);
			}
			for (var i = 0; i < pointArray.length; i++) {
				DDAline(pointArray[i][0], pointArray[i][1], pointArray[i][2], pointArray[i][3], ctx);
			}
		}
	});

	$('#clear1').click(function() {
		pointArray = new Array();
		count = 0;
		status = 0;
		//clearIt("myCanvas1");
		var c = document.getElementById("myCanvas1");
		var ctx = c.getContext("2d");
		ctx.clearRect(0, 0, 700, 400);
		ctx.globalCompositeOperation = "source-over";
	});
}

//code编码
function get_code(x, y, xw_xmin, yw_ymin, xw_xmax, yw_ymax) {
	var codeTemp = 0;
	if (y > yw_ymax)
		codeTemp |= TOP;
	else if (y < yw_ymin)
		codeTemp |= BOTTOM;
	if (x > xw_xmax)
		codeTemp |= RIGHT;
	else if (x < xw_xmin)
		codeTemp |= LEFT;
	return codeTemp;
}


//裁剪
function Line_Clipping(x1, y1, x2, y2, xw_xmin, yw_ymin, xw_xmax, yw_ymax) {
	LinePointBegin.x1 = x1;
	LinePointBegin.y1 = y1;
	LinePointBegin.x2 = x2;
	LinePointBegin.y2 = y2;
	console.log("矩形开始点：" + beginPoint.x + " " + beginPoint.y);
	console.log("矩形结束点：" + endPoint.x + " " + endPoint.y);
	console.log("处理之前x1, y1, x2, y2" + x1 + " " + y1 + " " + x2 + " " + y2);
	var code1, code2, code;
	var x, y;
	var draw = false;
	var done = false;
	code1 = get_code(x1, y1, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
	code2 = get_code(x2, y2, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
	console.log("code1:" + code1 + "code2:" + code2);
	while (!done) {
		if (code1 == 0 && code2 == 0) {
			draw = true;
			done = true;
		} else if ((code1 & code2) != 0) {
			done = true;
		} else {
			if (code1 != 0)
				code = code1;
			else
				code = code2;
			if ((code & TOP) != 0) {
				y = yw_ymax;
				x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
			} else if ((code & BOTTOM) != 0) {
				y = yw_ymin;
				x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
			} else if ((code & RIGHT) != 0) {
				x = xw_xmax;
				y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
			} else if ((code & LEFT) != 0) {
				x = xw_xmin;
				y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
			}
			if (code == code1) {
				x1 = x;
				y1 = y;
				code1 = get_code(x1, y1, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
			} else {
				x2 = x;
				y2 = y;
				code2 = get_code(x2, y2, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
			}
		}
	}

	////////重复部分开始/////////
	LinePointBegin.x1 = x1;
	LinePointBegin.y1 = y1;
	LinePointBegin.x2 = x2;
	LinePointBegin.y2 = y2;
	draw = false;
	done = false;
	code1 = get_code(x1, y1, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
	code2 = get_code(x2, y2, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
	console.log("code1:" + code1 + "code2:" + code2);
	while (!done) {
		if (code1 == 0 && code2 == 0) {
			draw = true;
			done = true;
		} else if ((code1 & code2) != 0) {
			done = true;
		} else {
			if (code1 != 0)
				code = code1;
			else
				code = code2;
			if ((code & TOP) != 0) {
				y = yw_ymax;
				x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
			} else if ((code & BOTTOM) != 0) {
				y = yw_ymin;
				x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
			} else if ((code & RIGHT) != 0) {
				x = xw_xmax;
				y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
			} else if ((code & LEFT) != 0) {
				x = xw_xmin;
				y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
			}
			if (code == code1) {
				x1 = x;
				y1 = y;
				code1 = get_code(x1, y1, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
			} else {
				x2 = x;
				y2 = y;
				code2 = get_code(x2, y2, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
			}
		}
	}
	LinePointEnd.x1 = x1;
	LinePointEnd.y1 = y1;
	LinePointEnd.x2 = x2;
	LinePointEnd.y2 = y2;
	console.log("处理之后x1, y1, x2, y2" + x1 + " " + y1 + " " + x2 + " " + y2);
	code1 = get_code(LinePointBegin.x1, LinePointBegin.y1, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
	code2 = get_code(LinePointBegin.x2, LinePointBegin.y2, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
	if (code1 != 0 && code2 != 0 && LinePointBegin.x1 == LinePointEnd.x1 && LinePointBegin.x2 == LinePointEnd.x2 && LinePointBegin.y1 == LinePointEnd.y1 && LinePointBegin.y2 == LinePointEnd.y2) {
		LinePointEnd.x1 = 0;
		LinePointEnd.y1 = 0;
		LinePointEnd.x2 = 0;
		LinePointEnd.y2 = 0;
	}
	////////重复部分结束/////////
}

function Line_ClippingAgain(x1, y1, x2, y2, xw_xmin, yw_ymin, xw_xmax, yw_ymax) {
	LinePointBegin.x1 = x1;
	LinePointBegin.y1 = y1;
	LinePointBegin.x2 = x2;
	LinePointBegin.y2 = y2;
	console.log("矩形开始点：" + beginPoint.x + " " + beginPoint.y);
	console.log("矩形结束点：" + endPoint.x + " " + endPoint.y);
	console.log("处理之前x1, y1, x2, y2" + x1 + " " + y1 + " " + x2 + " " + y2);
	var code1, code2, code;
	var x, y;
	var draw = false;
	var done = false;
	code1 = get_code(x1, y1, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
	code2 = get_code(x2, y2, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
	console.log("code1:" + code1 + "code2:" + code2);
	while (!done) {
		if (code1 == 0 && code2 == 0) {
			draw = true;
			done = true;
		} else if ((code1 & code2) != 0) {
			done = true;
		} else {
			if (code1 != 0)
				code = code1;
			else
				code = code2;
			if ((code & TOP) != 0) {
				y = yw_ymax;
				x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
			} else if ((code & BOTTOM) != 0) {
				y = yw_ymin;
				x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
			} else if ((code & RIGHT) != 0) {
				x = xw_xmax;
				y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
			} else if ((code & LEFT) != 0) {
				x = xw_xmin;
				y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
			}
			if (code == code1) {
				x1 = x;
				y1 = y;
				code1 = get_code(x1, y1, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
			} else {
				x2 = x;
				y2 = y;
				code2 = get_code(x2, y2, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
			}
		}
	}
	LinePointEnd.x1 = x1;
	LinePointEnd.y1 = y1;
	LinePointEnd.x2 = x2;
	LinePointEnd.y2 = y2;
	console.log("处理之后x1, y1, x2, y2" + x1 + " " + y1 + " " + x2 + " " + y2);
	code1 = get_code(LinePointBegin.x1, LinePointBegin.y1, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
	code2 = get_code(LinePointBegin.x2, LinePointBegin.y2, xw_xmin, yw_ymin, xw_xmax, yw_ymax);
	if (code1 != 0 && code2 != 0 && LinePointBegin.x1 == LinePointEnd.x1 && LinePointBegin.x2 == LinePointEnd.x2 && LinePointBegin.y1 == LinePointEnd.y1 && LinePointBegin.y2 == LinePointEnd.y2) {
		LinePointEnd.x1 = 0;
		LinePointEnd.y1 = 0;
		LinePointEnd.x2 = 0;
		LinePointEnd.y2 = 0;
	}
}

function drawCubiod(x0, y0, x1, y1, ctx) {
	DDAline(x0, y0, x1, y0, ctx);
	DDAline(x1, y0, x1, y1, ctx);
	DDAline(x1, y1, x0, y1, ctx);
	DDAline(x0, y1, x0, y0, ctx);
}