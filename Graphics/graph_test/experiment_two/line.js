		function DDAline(x0,y0,x1,y1,ctx){
			
			var arr=change(x1-x0,y1-y0);
			var xt=x0,yt=y0;
			x0=0,y0=0;
			x1=arr[0];y1=arr[1];
			var status=arr[2];
			
			var x,dx,dy,kx,ky,y;
			dx=x1-x0;
			dy=y1-y0;
			kx=dy/dx;
			ky=dx/dy;
			y=y0;
			if(x0<=x1){
				for(x=x0;x<=x1;x++){
				ctx.strokeRect(xt+changeX(x,y,status),yt+changeY(x,y,status),1,0);
				y=y+kx;
				}
			}else{
				for(x=x0;x>=x1;x--){
				ctx.strokeRect(xt+changeX(x,y,status),yt+changeY(x,y,status),1,0);
				y=y-kx;
				}
			}
			
			
		}
		
		function MidpointLine(x0,y0,x1,y1,ctx){
			
			var arr=change(x1-x0,y1-y0);
			var xt=x0,yt=y0;
			x0=0,y0=0;
			x1=arr[0];y1=arr[1];
			var status=arr[2];
			
			var a,b,delta1,delta2,d,x,y;
			a=y0-y1;
			b=x1-x0;
			d=a+a+b;
			delta1=a+a;
			delta2=a+b+a+b;
			x=x0;
			y=y0;
			//ctx.rect(x,y,1,0);

			while(x<x1){
				if(d<0){
					x++;
					y++;
					d+=delta2;
				}else{
					x++;
					d+=delta1;
				}
				
				ctx.strokeRect(xt+changeX(x,y,status),yt+changeY(x,y,status),1,0);
			}
		}
		
		function Integer_Bresenham_line(x0,y0,x1,y1,ctx){
			
			var arr=change(x1-x0,y1-y0);
			var xt=x0,yt=y0;
			x0=0,y0=0;
			x1=arr[0];y1=arr[1];
			var status=arr[2];
			
			var x,y,dx,dy,e;
			dx=Math.abs(x1-x0);
			dy=Math.abs(y1-y0);
			e=-dx;
			x=x0;
			y=y0;
			for(var i=0;i<=dx;i++){
				ctx.strokeRect(xt+changeX(x,y,status),yt+changeY(x,y,status),1,0);
				if(x0<=x1){
					x++;
				}else{
					x--;
				}
				e=e+2*dy;
				if(e>=0){
					y++;
					e=e-2*dx;
				}
			}
		}
		
		function change(x1,y1){
			var x0=0,y0=0;
			var dx=x1-x0;
			var dy=y1-y0;
			var status=0;
			if(dx>=0&&dy>=0&&Math.abs(dx)>=Math.abs(dy)){
				x1=x1;
				y1=y1;
				status=0;
			}else if(dx>=0&&dy>=0&&Math.abs(dx)<=Math.abs(dy)){
				var temp=y1;
				y1=x1;
				x1=temp;
				status=1;
			}else if(dx<=0&&dy>=0&&Math.abs(dx)<=Math.abs(dy)){
				var temp=y1;
				y1=-x1;
				x1=temp;
				status=2;
			}else if(dx<=0&&dy>=0&&Math.abs(dx)>=Math.abs(dy)){
				y1=y1;
				x1=-x1;
				status=3;
			}else if(dx<=0&&dy<=0&&Math.abs(dx)>=Math.abs(dy)){
				y1=-y1;
				x1=-x1;
				status=4;
			}else if(dx<=0&&dy<=0&&Math.abs(dx)<=Math.abs(dy)){
				var temp=y1;
				y1=-x1;
				x1=-temp;
				status=5;
			}else if(dx>=0&&dy<=0&&Math.abs(dx)<=Math.abs(dy)){
				var temp=y1;
				y1=x1;
				x1=-temp;
				status=6;
			}else if(dx>=0&&dy<=0&&Math.abs(dx)>=Math.abs(dy)){
				y1=-y1;
				x1=x1;
				status=7;
			}
			//alert("p0("+x0+","+y0+") p1("+x1+","+y1+")");
			//MidpointLine(x0,y0,x1,y1,ctx)
			var arr = [x1,y1,status];
			return arr;
		}
		
		function changeX(x,y,status){
			var xt,yt;
			if(status==0){
				xt=x;yt=y;
			}else if(status==1){
				xt=y;yt=x;
			}else if(status==2){
				xt=-y;yt=x;
			}else if(status==3){
				xt=-x;yt=y;
			}else if(status==4){
				xt=-x;yt=-y;
			}else if(status==5){
				xt=-y;yt=-x;
			}else if(status==6){
				xt=y;yt=-x;
			}else if(status==7){
				xt=x;yt=-y;
			}
			return xt;
		}
		
		function changeY(x,y,status){
			var xt,yt;
			if(status==0){
				xt=x;yt=y;
			}else if(status==1){
				xt=y;yt=x;
			}else if(status==2){
				xt=-y;yt=x;
			}else if(status==3){
				xt=-x;yt=y;
			}else if(status==4){
				xt=-x;yt=-y;
			}else if(status==5){
				xt=-y;yt=-x;
			}else if(status==6){
				xt=y;yt=-x;
			}else if(status==7){
				xt=x;yt=-y;
			}
			return yt;
		}