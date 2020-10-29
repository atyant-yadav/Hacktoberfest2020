clc;
clear all;


function [c,err,yc, k]=regula(f,a,b,delta)
% Input - f is the function input as a string ’f’
% a and b are the left and right endpoints
% fa and fb are f(a) and f(b) respectively
% fa and fb must have opposite signs
% delta is the tolerance
% Output - x1 is the approximate root
% fx1=f(x1)
% err is the error estimate for c
% k is the current iteration number
 
 
fa=feval(f,a);
fb=feval(f,b);

 
if fa*fb>0
    disp('Note : fa*fb > 0')
end
max_iteration = 30;
epsilon = 10^-7;
 
for k=1:max_iteration
    dx = yb*(b-a)/(yb-ya);
    c = b-dx;
    ac = c-a;
    yc = feval(f,c);


    if yc==0
        break
    elseif yc*yb>0
        b=c;
        yb=yc;
    else
        a=c;
        ya=yc;
    end
    dx = min(abs(dx),ac);
    if abs()<delta,
        break
    end
    if abs(yc)<delta,
      break
    end
end

 
c;
err=abs(b-a);
yc=feval(f,c);
