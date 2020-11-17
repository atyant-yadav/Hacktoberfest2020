# Plot of two different lines, graphical propagation of Cosine and Sine.

% a) created this file named 'twoLinePlot.m'
% b) using figure command
% c)
  % c) i)
        t=linspace(0,2*pi,100)
        
  %    ii)
        x=sin(t) 
        figure(1)
        plot(t,x)
        
  %   iii)
        hold on
        
  %    iv)
        y=cos(t)
        figure(1)
        plot(t,y,'r--')
        hold off
        
% d)
  % d) i)
        xlabel('Time(s)')
        
  %   ii)
        ylabel('Function value')
        
  %  iii)
        title('Sin and Cos Function')
  
% e)
        legend('Sin','Cos','Location','NorthEast')
% f)
        xlim([0,2*pi])
        ylim([-1.4,1.4])
  
  
