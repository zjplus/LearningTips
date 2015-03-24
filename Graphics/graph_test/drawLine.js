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
function showCoord(id,coordinates) {
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
function drawLine(canvasId){
	//canvas部分
	var canvas = document.getElementById(canvasId);
	//起始点坐标
	var beginPoint=new Object();
	//鼠标监听事件mousedown
	canvas.addEventListener("mousedown", function (event) {
		beginPoint.x=event.layerX;
		beginPoint.y=event.layerY;
	});
	
	//鼠标监听事件mousemove
	canvas.addEventListener("mousemove",function (event){
	});
	
	//结束点坐标
	var endPoint=new Object();
	////鼠标监听事件mouseup
	canvas.addEventListener("mouseup",function(event){
		endPoint.x=event.layerX;
		endPoint.y=event.layerY;
		//$('#absoluteCoord1').innerHTML="相对坐标：(X,Y)=("+event.layerX+","+event.layerY+")";
		if (canvas.getContext) {
		var ctx = canvas.getContext('2d');
		ctx.beginPath(); // 开始路径绘制	
		ctx.translate(0.5,0.5); 
		if(canvasId=="canvas1"){
			//数值微分算法
			DDALine(beginPoint.x,beginPoint.y,endPoint.x,endPoint.y,ctx);
		}else if(canvasId=="canvas2"){
			//中点画线法
			MDPLine(beginPoint.x,beginPoint.y,endPoint.x,endPoint.y,ctx);
		}else if(canvasId=="canvas3"){
			//Bresenham画线算法
			BresenhamLine(beginPoint.x,beginPoint.y,endPoint.x,endPoint.y,ctx);
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
function DDALine(x0,y0,x1,y1,ctx){
	var dx,dy,k,y;
	var temp;
	dx=x1-x0;
	dy=y1-y0;
	k=dy/dx;
	//|k|<1时
	if(k<1&&k>-1||k==1||k==-1){
		//如果x0>x1，交换画线两点位置
		if(x0>x1){
			temp=x0;
			x0=x1;
			x1=temp;
			temp=y0;
			y0=y1;
			y1=temp;
		}
		y=y0;
		var point=new Object();
		point.x=0;
		point.y=y;
		for(x=x0;x<x1;x++){
			point.x=x;
			point.y=point.y+k;
			drawPoint(ctx,point);
		}
	}
	//|k|>1时
	else if(k>1||k<-1){
		//如果y0>y1，交换画线两点位置
		if(y0>y1){
			temp=x0;
			x0=x1;
			x1=temp;
			temp=y0;
			y0=y1;
			y1=temp;
		}
		x=x0;
		var point=new Object();
		point.x=x;
		point.y=0;
		for(y=y0;y<y1;y++){
			point.x=point.x+1/k;
			point.y=y;
			drawPoint(ctx,point);
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
function MDPLine(x0,y0,x1,y1,ctx){
	var a,b,delta1,delta2,d,x,y;
	a=y0-y1;
	b=x1-x0;
	d=2*a+b;
	delta1=2*a;
	delta2=2*(a+b);
	x=x0;
	y=y0;
	var point =new Object();
	point.x=x;
	point.y=y;
	drawPoint(ctx,point);
	while(x<x1){
		if(d<0){
			x++;
			y++;
			d+=delta12;
		}else{
			x++;
			d+=delta1;
		}
		point.x=x;
		point.y=y;
		drawPoint(ctx,point);
	}/*while*/
}/*MidPointLine*/

/**
 * Bresenham画线算法
 * @param {Object} x0 
 * @param {Object} y0
 * @param {Object} x1
 * @param {Object} y1
 * @param {Object} ctx canvas的context对象
 */
function BresenhamLine(x0,y0,x1,y1,ctx){
	alert("haha");
}
