
tspan = 0:0.01:19.99;
options = odeset('RelTol', 1e-13, 'AbsTol',1e-13);
[t,y] = ode45(@vdp1,[0 19.99],[2; 0],options);
%plot(t,y(:,1),'-o',t,y(:,2),'-o')
%cicciobarubba
Folder = cd;
Folder = fullfile(Folder,'..');
ODE_data = readmatrix(fullfile(Folder,'sim.csv'));
subplot(2,2,1);
plot(ODE_data(:,1),ODE_data(:,2),t,y(:,1));
subplot(2,2,2);
plot(ODE_data(:,1),ODE_data(:,3),t,y(:,2));
subplot(2,2,4);
plot(ODE_data(:,1),ODE_data(:,4));
subplot(2,2,3);
plot(ODE_data(:,2),ODE_data(:,3));

ode_45data = interp1(t,y(:,1),tspan)';
qerror = log10(abs(ODE_data(:,2)-ode_45data));
hfigure = figure(2);
plot(tspan,qerror,'.r');
