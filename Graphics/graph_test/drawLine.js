function cilcktab1() {
	$('#tab1').addClass("active");
	$('#tab2').removeClass();
	$("#tab3").removeClass();
	$('#drowBoard1').css("display", "block");
	$('#drowBoard2').css("display", "none");
	$('#drowBoard3').css("display", "none");
}

function cilcktab2() {
	$('#tab1').removeClass();
	$('#tab2').addClass("active");
	$("#tab3").removeClass();
	$('#drowBoard1').css("display", "none");
	$('#drowBoard2').css("display", "block");
	$('#drowBoard3').css("display", "none");
}

function cilcktab3() {
	$('#tab1').removeClass();
	$('#tab2').removeClass();
	$("#tab3").addClass("active")
	$('#drowBoard1').css("display", "none");
	$('#drowBoard2').css("display", "none");
	$('#drowBoard3').css("display", "block");
}

/**
 * 显示绝对坐标
 */
function showCoord(id, coordinates) {
	var coords1 = document.getElementById(id);
	coords1.onmousemove = function(e) {
		var pointer = getCoord(e);
		var coord = document.getElementById(coordinates);
		coord.innerHTML = "绝对坐标：X,Y=(" + pointer.x + ", " + pointer.y + ")";
	}
}

/*
 * 获取绝对位置pointer
 */
function getCoord(e) {
	e = e || window.event;
	var x = e.pageX || (e.clientX +
		(document.documentElement.scrollLeft || document.body.scrollLeft));
	var y = e.pageY || (e.clientY +
		(document.documentElement.scrollTop || document.body.scrollTop));
	return {
		'x': x,
		'y': y
	};
}

/**
 * 描点
 * @param {Object} ctx canvas的context对象
 * @param {Object} point 坐标点
 */
function drawPoint(ctx, point) {
	ctx.moveTo(point.x, point.y);
	ctx.lineTo(point.x + 1, point.y + 1);
}


/**
 * 画线函数
 * @param {Object} canvasId
 */
function drawLine(canvasId) {
	//canvas部分
	var canvas = document.getElementById(canvasId);
	//起始点坐标
	var beginPoint = new Object();
	//鼠标监听事件mousedown
	canvas.addEventListener("mousedown", function(event) {
		beginPoint.x = event.layerX - 15;
		beginPoint.y = event.layerY - 15;
	});

	//鼠标监听事件mousemove
	canvas.addEventListener("mousemove", function(event) {});

	//结束点坐标
	var endPoint = new Object();
	////鼠标监听事件mouseup
	canvas.addEventListener("mouseup", function(event) {
		endPoint.x = event.layerX - 15;
		endPoint.y = event.layerY - 15;
		//$('#absoluteCoord1').innerHTML="相对坐标：(X,Y)=("+event.layerX+","+event.layerY+")";
		if (canvas.getContext) {
			var ctx = canvas.getContext('2d');
			ctx.beginPath(); // 开始路径绘制	
			ctx.translate(0.5, 0.5);
			if (canvasId == "canvas1") {
				//数值微分算法
				DDALine(beginPoint.x, beginPoint.y, endPoint.x, endPoint.y, ctx);
			} else if (canvasId == "canvas2") {
				//中点画线法
				MDPLine(beginPoint.x, beginPoint.y, endPoint.x, endPoint.y, ctx);
			} else if (canvasId == "canvas3") {
				//Bresenham画线算法
				BresenhamLine(beginPoint.x, beginPoint.y, endPoint.x, endPoint.y, ctx);
			}

			ctx.lineWidth = 1; // 设置线宽
			ctx.strokeStyle = "#000000"; // 设置线的颜色
			ctx.stroke(); // 进行线的着色，这时整条线才变得可见
		}
	});
}


/**
 * 数值微分算法
 * @param {Object} x0
 * @param {Object} y0
 * @param {Object} x1
 * @param {Object} y1
 * @param {Object} ctx canvas的context对象
 */
function DDALine(x0, y0, x1, y1, ctx) {
	var dx, dy, k, y;
	var temp;
	dx = x1 - x0;
	dy = y1 - y0;
	k = dy / dx;
	//|k|<1时
	if (k < 1 && k > -1 || k == 1 || k == -1) {
		//如果x0>x1，交换画线两点位置
		if (x0 > x1) {
			temp = x0;
			x0 = x1;
			x1 = temp;
			temp = y0;
			y0 = y1;
			y1 = temp;
		}
		y = y0;
		var point = new Object();
		point.x = 0;
		point.y = y;
		for (x = x0; x < x1; x++) {
			point.x = x;
			point.y = point.y + k;
			drawPoint(ctx, point);
		}
	}
	//|k|>1时
	else if (k > 1 || k < -1) {
		//如果y0>y1，交换画线两点位置
		if (y0 > y1) {
			temp = x0;
			x0 = x1;
			x1 = temp;
			temp = y0;
			y0 = y1;
			y1 = temp;
		}
		x = x0;
		var point = new Object();
		point.x = x;
		point.y = 0;
		for (y = y0; y < y1; y++) {
			point.x = point.x + 1 / k;
			point.y = y;
			drawPoint(ctx, point);
		}
	}
}

/**
 * 中点画线法
 * @param {Object} x0
 * @param {Object} y0
 * @param {Object} x1
 * @param {Object} y1
 * @param {Object} ctx canvas的context对象
 */
function MDPLine(x0, y0, x1, y1, ctx) {
	//保证x0大于x1
	if (x0 > x1) {
		temp = x0;
		x0 = x1;
		x1 = temp;
		temp = y0;
		y0 = y1;
		y1 = temp;
	}
	var dx, dy, d, x, y;
	dy = y1 - y0;
	dx = x1 - x0;
	k = dy / dx;
	x = x0;
	y = y0;
	var point = new Object();
	point.x = x;
	point.y = y;
	console.log("X:" + point.x + "Y:" + point.y);
	drawPoint(ctx, point);
	if (k > 0 && k < 1) {
		d = (dy * 2) - dx;
		while (x < x1) {
			if (d > 0) {
				d += (dy - dx) * 2; /* 选择p2点 */
				x++;
				y++;
			} else {
				d += dy * 2; /* 选择p1点 */
				x++;
			}
			point.x = x;
			point.y = y;
			console.log("X:" + point.x + "Y:" + point.y);
			drawPoint(ctx, point);
		} /*while*/
	} else if (k > 1) {
		d = dy - (dx * 2);
		while (y < y1) {
			if (d < 0) {
				d += (dy - dx) * 2; /* 选择p2点 */
				x++;
				y++;
			} else {
				d += (-dx) * 2; /* 选择p点 */
				y++;
			}
			point.x = x;
			point.y = y;
			console.log("X:" + point.x + "Y:" + point.y);
			drawPoint(ctx, point);
		} /*while*/
	} else if (k > -1 && k < 0) {
		d = (dy * 2) + dx; /* d = 2a-b */
		while (x < x1) {
			if (d < 0) {
				d += (dy + dx) * 2; /* 选择p2点 */
				x++;
				y--;
			} else {
				d += dy * 2; /* 选择p点 */
				x++;
			}
			point.x = x;
			point.y = y;
			console.log("X:" + point.x + "Y:" + point.y);
			drawPoint(ctx, point);
		} /*while*/
	} else if (k < -1) {
		d = dy + (dx * 2); /* d = a - 2b */
		while (y > y1) {
			if (d > 0) {
				d += (dy + dx) * 2; /* 选择p2点 */
				x++;
				y--;
			} else {
				d += (dx) * 2; /* 选择p点 */
				y--;
			}
			point.x = x;
			point.y = y;
			console.log("X:" + point.x + "Y:" + point.y);
			drawPoint(ctx, point);
		} /*while*/
	}
} /*MidPointLine*/


/**
 * Bresenham画线算法
 * @param {Object} x0
 * @param {Object} y0
 * @param {Object} x1
 * @param {Object} y1
 * @param {Object} ctx canvas的context对象
 */
function BresenhamLine(x1, y1, x2, y2, ctx) {
	var point = new Object();
	var dx = x2 - x1;
	var dy = y2 - y1;
	var ux = ((dx > 0) << 1) - 1; //x的增量方向，取或-1
	var uy = ((dy > 0) << 1) - 1; //y的增量方向，取或-1
	var x = x1,
		y = y1,
		eps = 0; //eps为累加误差
	dx = Math.abs(dx);
	dy = Math.abs(dy);
	if (dx > dy) {
		for (x = x1; x != x2 + ux; x += ux) {
			point.x = x;
			point.y = y;
			drawPoint(ctx, point);
			eps += dy;
			if ((eps << 1) >= dx) {
				y += uy;
				eps -= dx;
			}
		}
	} else {
		for (y = y1; y != y2 + uy; y += uy) {
			point.x = x;
			point.y = y;
			drawPoint(ctx, point);
			eps += dx;
			if ((eps << 1) >= dy) {
				x += ux;
				eps -= dy;
			}
		}
	}
}

function swap(x0, y0, x1, y1) {
	temp = x0;
	x0 = x1;
	x1 = temp;
	temp = y0;
	y0 = y1;
	y1 = temp;
}

/**
 * 清除画布
 * @param {Object} ctx context
 */
function clearIt(canvasId) {
	var canvas = document.getElementById(canvasId);
	var ctx = canvas.getContext('2d');
	ctx.clearRect(0, 0, 740, 430);
	// source-over 是 context.globalCompositeOperation 的默认值
	ctx.globalCompositeOperation = "source-over";
}