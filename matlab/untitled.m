%cicciobarubba
Folder = cd;
Folder = fullfile(Folder,'..');
ODE_data = readmatrix(fullfile(Folder,'sim1.csv'));
subplot(2,2,1);
plot(ODE_data(:,1),ODE_data(:,2));
subplot(2,2,2);
plot(ODE_data(:,1),ODE_data(:,3));
subplot(2,2,4);
plot(ODE_data(:,1),ODE_data(:,4));
subplot(2,2,3);
plot(ODE_data(:,2),ODE_data(:,3));
