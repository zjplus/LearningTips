function filling(canvasId) {
	var count = 0;
	var beginPoint = new Object();
	var endPoint = new Object();
	var c = document.getElementById(canvasId);
	var ctx = c.getContext("2d");
	var hx = c.getBoundingClientRect().left; // 元素左边距离页面左边的距离
	var hy = c.getBoundingClientRect().top; // 元素上边距离页面上边的距离
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
				ctx.strokeStyle = "#333399";
				drawCubiod(beginPoint.x, beginPoint.y, endPoint.x, endPoint.y, ctx);
				ctx.stroke();
			} else if (count == 2) {
				//点击区域
				var P = new Object();
				P.x = xt - hx;
				P.y = yt - hy;
				var x0 = beginPoint.x;
				var y0 = beginPoint.y;
				var x1 = endPoint.x;
				var y1 = endPoint.y;
				var midx = 0.5 * (beginPoint.x + endPoint.x);
				var midy = 0.5 * (beginPoint.y + endPoint.y);
				if ($('input:radio[name="ways"]:checked').val() == 1 || $('input:radio[name="ways"]:checked').val() == 3) {
					if (P.x > x0 && P.x < midx && P.y > y0 && P.y < midy) {
						edgeFilling(x0, y0, midx, midy, ctx);
						//seed(P.x, P.y, ctx);
					} else if (P.x > midx && P.x < x1 && P.y > y0 && P.y < midy) {
						edgeFilling(midx, y0, x1, midy, ctx);
					} else if (P.x > x0 && P.x < midx && P.y > midy && P.y < y1) {
						edgeFilling(x0, midy, midx, y1, ctx);
					} else if (P.x > midx && P.x < x1 && P.y > midy && P.y < y1) {
						edgeFilling(midx, midy, x1, y1, ctx);
					}
				} else if ($('input:radio[name="ways"]:checked').val() == 2) {
					if (P.x > x0 && P.x < midx && P.y > y0 && P.y < midy) {
						seed1(P.x, P.y, ctx);
					} else if (P.x > midx && P.x < x1 && P.y > y0 && P.y < midy) {
						seed2(P.x, P.y, ctx);
					} else if (P.x > x0 && P.x < midx && P.y > midy && P.y < y1) {
						seed3(P.x, P.y, ctx);
					} else if (P.x > midx && P.x < x1 && P.y > midy && P.y < y1) {
						edgeFilling(midx, midy, x1, y1, ctx);
					}
				}

				function seed1(x, y, ctx) {
					var colorS = $('#color').val();
					ctx.strokeStyle = colorS;
					ctx.strokeRect(x, y, 1, 0);
					for (m = y0 + 1; m < midy - 1; m++) {
						for (n = x; n < midx; n++) {
							ctx.strokeRect(n, m, 1, 0);
						}
					}
					for (m = y0 + 1; m < midy - 1; m++) {
						for (n = x; n > x0 + 1; n--) {
							ctx.strokeRect(n, m, 1, 0);
						}
					}
				}

				function seed2(x, y, ctx) {
					var colorS = $('#color').val();
					ctx.strokeStyle = colorS;
					ctx.strokeRect(x, y, 1, 0);
					for (m = y0 + 1; m < midy - 1; m++) {
						for (n = x; n < x1; n++) {
							ctx.strokeRect(n, m, 1, 0);
						}
					}
					for (m = y0 + 1; m < midy - 1; m++) {
						for (n = x; n > midx + 1; n--) {
							ctx.strokeRect(n, m, 1, 0);
						}
					}
				}

				function seed3(x, y, ctx) {
					var colorS = $('#color').val();
					ctx.strokeStyle = colorS;
					ctx.strokeRect(x, y, 1, 0);
					for (m = midy + 1; m < y1; m++) {
						for (n = x; n < midx; n++) {
							ctx.strokeRect(n, m, 1, 0);
						}
					}
					for (m = midy + 1; m < y1; m++) {
						for (n = x; n > x0 + 1; n--) {
							ctx.strokeRect(n, m, 1, 0);
						}
					}
				}

				function seed4(x, y, ctx) {
					var colorS = $('#color').val();
					ctx.strokeStyle = colorS;
					ctx.strokeRect(x, y, 1, 0);
					for (m = midy + 1; m < y1; m++) {
						for (n = x; n < x1; n++) {
							ctx.strokeRect(n, m, 1, 0);
						}
					}
					for (m = midy + 1; m < y1; m++) {
						for (n = x; n < x1; n++) {
							ctx.strokeRect(n, m, 1, 0);
						}
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
			ctx.strokeStyle = "#333399";
			drawCubiod(beginPoint.x, beginPoint.y, endPoint.x, endPoint.y, ctx);
			ctx.stroke();
		}
	});

	$('#clear1').click(function() {
		count = 0;
		//clearIt("myCanvas1");
		var c = document.getElementById("myCanvas1");
		var ctx = c.getContext("2d");
		ctx.clearRect(0, 0, 700, 400);
		ctx.globalCompositeOperation = "source-over";
	});
	//	function clearIt() {
	//	count = 0;
	////	var c = document.getElementById(canvasId);
	////	var ctx = c.getContext("2d");
	//	ctx.clearRect(0, 0, 700, 400);
	//	ctx.globalCompositeOperation = "source-over";
	//};
}



function drawCubiod(x0, y0, x1, y1, ctx) {
	DDAline(x0, y0, x1, y0, ctx);
	DDAline(x1, y0, x1, y1, ctx);
	DDAline(x1, y1, x0, y1, ctx);
	DDAline(x0, y1, x0, y0, ctx);
	DDAline(0.5 * (x0 + x1), y0, 0.5 * (x0 + x1), y1, ctx);
	DDAline(x0, 0.5 * (y0 + y1), x1, 0.5 * (y0 + y1), ctx);
}

function edgeFilling(x0, y0, x1, y1, ctx) {
	var colorS = $('#color').val();
	ctx.strokeStyle = colorS;
	var width = x1 - x0;
	for (m = y0 + 1; m < y1 - 1; m++) {
		for (n = x0 + 1; n < width + x0 - 1; n++) {
			ctx.strokeRect(n, m, 1, 0);
		}
	}
}

function seedFilling(x0, y0, ctx) {
	var colorS = $('#color').val();
	ctx.strokeStyle = colorS;
	ctx.strokeRect(x0, y0, 1, 0);
	console.log("is excuting!");
	//x0=x0+1;
	//	seedFilling(x0-1, y0, ctx);
	//	seedFilling(x0, y0 + 1, ctx);
	//	seedFilling(x0, y0 - 1, ctx);
	if (GetPixel(x0 + 2, y0, ctx) != "#333399") {
		seedFilling(x0 + 2, y0, ctx) //右
	}
	if (GetPixel(x0 - 1, y0, ctx) != "#333399") {
		seedFilling(x0 - 1, y0, ctx) //左
	}
	if (GetPixel(x0, y0 + 1, ctx) != "#333399") {
		seedFilling(x0, y0 + 1, ctx) //上
	}
	if (GetPixel(x0, y0 - 1, ctx) != "#333399") {
		seedFilling(x0, y0 - 1, ctx) //下
	}
	//	alert(GetPixel(x0 + 5, y0, ctx));
	//	alert(GetPixel(x0 - 5, y0, ctx));
	//	alert(GetPixel(x0, y0 + 5, ctx));
	//	alert(GetPixel(x0, y0 - 5, ctx));
}


function GetPixel(x, y, ctx) {
	var p = ctx.getImageData(x, y, 1, 1).data;
	var hex = "#" + ("000000" + rgbToHex(p[0], p[1], p[2])).slice(-6);
	return hex;
}

function rgbToHex(r, g, b) {
	if (r > 255 || g > 255 || b > 255)
		throw "Invalid color component";
	return ((r << 16) | (g << 8) | b).toString(16);
}