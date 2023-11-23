clear
clc
%test values:
%crit = HarmonicMotion(10,5,(10*sqrt(2)),0.5,0.5,10,1000);
%under = HarmonicMotion(10, 5, 10, 0.5, 0.5, 10, 1000);
%over = HarmonicMotion(10,5,20,0.5,0.5,10,1000);
%nodamping = HarmonicMotion(10, 5, 0, 0.5, 0.5, 10, 1000);
zeta = [(10*sqrt(2)),10,20,0];
%build overlayed plot
figure(1);
hold on;
title("Time-Domain Response of Damped Systems");

xlabel("Time(s)");
ylabel("Displacement");
names = [];
for i = 1:4  
    [x,y,damping] = HarmonicMotion(10,5,(zeta(i)),0.5,0.5,10,1000);
    plot(y,x); 
    names = [names, damping];
end
legend(names);
   

%build seperate aligned plots
figure(2);

for i = 1:4  
    subplot(4,1,i);
    
    [x,y,damping] = HarmonicMotion(10,5,(zeta(i)),0.5,0.5,10,1000);
   plot(y,x);
   if i == 1
        title("Time-Domain Response of Damped Systems");
   end       
        ylabel(damping);
        xlabel("Time(s)");
        ylim([-1 1]);
        xlim([0 10]);
end




