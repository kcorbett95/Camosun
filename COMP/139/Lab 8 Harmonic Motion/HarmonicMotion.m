function [x,t,damping] = harmonicMotion(m, k, b, x0, v0, tN, N)
%harmonicMotion 
% Inputs (all scalar):
% m = mass
% k = spring constant
% b = damping coefficient
% x0 = initial displacement
% v0 = initial velocity
% tN = final time (initial time = 0)
% N = number of points in time
% Outputs:
% x = vector of N displacement values
% t = vector of N time values
% damping = a string containing 'undamped', 'underdamped', 'critical', or 'overdamped'
validateattributes(m, {'numeric'},{'scalar','positive'},1);
validateattributes(k, {'numeric'},{'scalar','nonnegative'},2);
validateattributes(b, {'numeric'},{'scalar','nonnegative'},3);
validateattributes(x0, {'numeric'},{'scalar'},4);
validateattributes(v0, {'numeric'},{'scalar'},5);
validateattributes(tN, {'numeric'},{'scalar','positive'},6);

und = "Undamped";
under = "Under-damped";
over = "Over-damped";
crit = "Critically damped";
zeta = b/(2*sqrt(m*k));
W0 = sqrt((k/m));
W1 = W0*sqrt(1-(zeta^2));
t = linspace(0,tN,N);

%test values:
%crit = HarmonicMotion(10,5,10*sqrt(2),0.5,0.5,10,1000);
%under = HarmonicMotion(10, 5, 10, 0.5, 0.5, 10, 1000);
%over = HarmonicMotion(10,5,20,0.5,0.5,10,1000);
%nodamping = HarmonicMotion(10, 5, 0, 0.5, 0.5, 10, 1000);

if zeta == 0
    %disp(und)
    damping = und;
    A = x0;
    B = v0/W0;
    x(1:N) = (A*cos(W0*t))+(B*sin(W0*t));
end

if zeta < 1 && zeta > 0
    %disp(under)
    damping = under;
    A = x0;
    B = ((zeta*W0*x0)+v0)/W1;
    x(1:N) = (exp(-zeta*W0*t)).*((A*cos(W1*t))+(B*sin(W1*t)));
end

if zeta > 1
    %disp(over)
    damping = over;
    gamma1 = W0*(-zeta+sqrt((zeta^2)-1));
    gamma2 = W0*(-zeta-sqrt((zeta^2)-1));  
    B = -((gamma1*x0)-v0)/(gamma2 - gamma1);
    A = x0-B;
    x(1:N) = (A*(exp(gamma1*t)))+(B*(exp(gamma2*t)));
end

if zeta == 1
    %disp(crit)
    damping = crit;
    A = x0;
    B = (W0*x0)+v0;
    x(1:N) = (exp(-W0*t)).*(A+(B*t));
end


end

