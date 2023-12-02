clear
clc
%test values:
%crit = HarmonicMotion(10,5,(10*sqrt(2)),0.5,0.5,10,1000);
%under = HarmonicMotion(10, 5, 10, 0.5, 0.5, 10, 1000);
%over = HarmonicMotion(10,5,20,0.5,0.5,10,1000);
%nodamping = HarmonicMotion(10, 5, 0, 0.5, 0.5, 10, 1000);
% m = mass
% k = spring constant
% b = damping coefficient
% x0 = initial displacement
% v0 = initial velocity
% tN = final time (initial time = 0)
% N = number of points in time
m = 10;
k = 5;
x0 = 0.5;
v0 = 0.5;
tN = 10;
N = 1000;
b = [(10*sqrt(2)),10,20,0];

%build overlayed plot
figure(1);
hold on;
title("Time-Domain Response of Damped Systems");

xlabel("Time(s)");
ylabel("Displacement");
names = [];
for i = 1:4  
    [x,y,damping] = HarmonicMotion(m, k, b(i), x0, v0, tN, N);
    plot(y,x); 
    names = [names, damping];
end
legend(names);
   

%build seperate aligned plots
figure(2);

for i = 1:4  
    subplot(4,1,i);
    
    [x,y,damping] = HarmonicMotion(m, k, b(i), x0, v0, tN, N);
   plot(y,x);
   if i == 1
        title("Time-Domain Response of Damped Systems");
   end       
        ylabel(damping);
        xlabel("Time(s)");
        ylim([-1 1]);
        xlim([0 10]);
end




