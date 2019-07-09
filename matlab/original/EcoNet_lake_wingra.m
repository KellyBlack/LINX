% This file is automatically generated by EcoNet(http://eco.engr.uga.edu).
% Run this M-file in Matlab to load all results into Matlab environment.
%
% ================== EcoNet Model ===================
% #  LAKE WINGRA, RICHEY ET AL. SCIENCE 202%3A1185, GC%2FM2%2FYR
% #  5  3
% * ->  ZOOPLANKTON     c=4.9
% * ->  PARTICULATE_ORGANIC_CARBO     c=474
% ZOOPLANKTON ->  FISH       c=6.6
% ZOOPLANKTON ->  SEDIMENT       c=2.5
% BENTHOS ->  FISH       c=0.6
% BENTHOS ->  SEDIMENT       c=28.7
% FISH ->  SEDIMENT       c=1.5
% PARTICULATE_ORGANIC_CARBO ->  ZOOPLANKTON       c=52.2
% PARTICULATE_ORGANIC_CARBO ->  SEDIMENT       c=560
% SEDIMENT ->  BENTHOS       c=34.9
% SEDIMENT ->  PARTICULATE_ORGANIC_CARBO       c=330
% ZOOPLANKTON ->  *      c=48
% BENTHOS ->  *      c=5.6
% FISH ->  *      c=5.7
% PARTICULATE_ORGANIC_CARBO ->  *      c=191.8
% SEDIMENT ->  *      c=227.8
% ZOOPLANKTON = 1
% BENTHOS = 1
% FISH = 1
% PARTICULATE_ORGANIC_CARBO = 1
% SEDIMENT = 1
% 
% % ===================================================


% Compartment Names (NM):

NM = { 'ZOOPLANKTON'
'BENTHOS'
'FISH'
'PARTICULATE_ORGANIC_CARBO'
'SEDIMENT'
};

% Environmental inputs (Z):

Z = [ 4.900000000000000e+00
0.000000000000000e+00
0.000000000000000e+00
4.740000000000000e+02
0.000000000000000e+00
];

% Environmental Outputs (Y):

Y = [ 4.799998127168907e+01
5.600001463300787e+00
5.700000012154430e+00
1.918015543731231e+02
2.277981128942769e+02
];

% Initial storage values (IC):

IC = [ 1.000000000000000e+00
1.000000000000000e+00
1.000000000000000e+00
1.000000000000000e+00
1.000000000000000e+00
];

%  Final storage values - assumed Steady-state (SS):

SS = [ 9.999996098268557e-01
1.000000261303712e+00
1.000000002132356e+00
1.000008104135157e+00
9.999917159538053e-01
];

% Output throughflow (T):

T = [ 5.709997772111346e+01
3.490000911949954e+01
7.200000015352964e+00
8.040065157246662e+02
5.926950900458205e+02
];

% Input hroughflow (TP):

TP = [ 5.710042303585519e+01
3.489971088678780e+01
7.199997581639474e+00
8.039972662647558e+02
5.927045448428701e+02
];

% Residence times (RT):

RT = [ 1.751313485113835e-02
2.865329512893984e-02
1.388888888888889e-01
1.243781094527363e-03
1.687194196051965e-03
];

% Stoichiometric matrix (SM):

SM = [     1.000000000000000e+00    0.000000000000000e+00   -1.000000000000000e+00   -1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00   -1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00   -1.000000000000000e+00   -1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00   -1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    1.000000000000000e+00    0.000000000000000e+00    1.000000000000000e+00    0.000000000000000e+00   -1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00   -1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00   -1.000000000000000e+00   -1.000000000000000e+00    0.000000000000000e+00    1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00   -1.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    1.000000000000000e+00    0.000000000000000e+00    1.000000000000000e+00    1.000000000000000e+00    0.000000000000000e+00    1.000000000000000e+00   -1.000000000000000e+00   -1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00   -1.000000000000000e+00

];

% Adjacency Matrix (A):

A = [     0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    1.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    1.000000000000000e+00
    1.000000000000000e+00    1.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    1.000000000000000e+00
    1.000000000000000e+00    1.000000000000000e+00    1.000000000000000e+00    1.000000000000000e+00    0.000000000000000e+00

];

% Flow Matrix (F):

F = [     0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    5.220042303585520e+01    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    3.489971088678780e+01
    6.599997424857247e+00    6.000001567822272e-01    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    3.299972662647558e+02
    2.499999024567139e+00    2.870000749941653e+01    1.500000003198534e+00    5.600045383156879e+02    0.000000000000000e+00

];

% Normalized flow matrix (G):

G = [     0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    6.492537313432836e-02    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    5.888307744221358e-02
    1.155866900175131e-01    1.719197707736390e-02    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    5.567740846971485e-01
    4.378283712784588e-02    8.223495702005731e-01    2.083333333333333e-01    6.965174129353234e-01    0.000000000000000e+00

];

% Throughflow Analysis (N):

N = [     1.004372004387832e+00    5.320946343998777e-02    1.342158336264508e-02    1.100813864525308e-01    6.442360014069637e-02
    7.121600738465487e-03    1.086673415786641e+00    2.186254850356878e-02    7.355507205987660e-02    1.049402328171301e-01
    1.162144699300945e-01    2.483237021142073e-02    1.001927216828408e+00    1.398850020536400e-02    9.250640776360218e-03
    6.733891815741004e-02    8.195480575814208e-01    2.067232379993610e-01    1.695506412027486e+00    9.922715423969325e-01
    1.209447781572635e-01    1.471957980995479e+00    3.712874641279433e-01    1.249171667905125e+00    1.782179827814127e+00

];

% Normalized flow matrix - output oriented (GP):

GP = [     0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    9.141934046071162e-01    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    9.999914546523263e-01
    9.166663070532921e-01    8.333335493094628e-02    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    4.104410347561960e-01
    4.218018786647731e-03    4.842288721709804e-02    2.530812264840208e-03    9.448442339422698e-01    0.000000000000000e+00

];

% Throughflow Analysis - output oriented (NP):

NP = [     1.004372004387832e+00    3.252209253686970e-02    1.692389459223440e-03    1.550020779344604e+00    6.687139471920863e-01
    1.165166582371585e-02    1.086673415786641e+00    4.510324023766540e-03    1.694519820847146e+00    1.782164598467882e+00
    9.216449485735312e-01    1.203680479151897e-01    1.001927216828408e+00    1.562061845325862e+00    7.615012994770913e-01
    4.782362644270836e-03    3.557463045890864e-02    1.851237878871770e-03    1.695506412027486e+00    7.314797326496496e-01
    1.165176539210214e-02    8.667415644744232e-02    4.510362566382805e-03    1.694534301231895e+00    1.782179827814127e+00

];

% Partial turnover rate matrix (C):

C = [    -5.710000000000000e+01    0.000000000000000e+00    0.000000000000000e+00    5.220000000000000e+01    0.000000000000000e+00
    0.000000000000000e+00   -3.489999999999999e+01    0.000000000000000e+00    0.000000000000000e+00    3.490000000000000e+01
    6.600000000000000e+00    6.000000000000000e-01   -7.200000000000000e+00    0.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00   -8.040000000000000e+02    3.300000000000000e+02
    2.500000000000000e+00    2.870000000000000e+01    1.500000000000000e+00    5.600000000000000e+02   -5.927000000000000e+02

];

% Storage Analysis (S):

S = [     1.758970235355222e-02    9.318645085812225e-04    2.350539993457983e-04    1.927870165543447e-03    1.128259196859832e-03
    2.040573277497276e-04    3.113677409130778e-02    6.264340545435185e-04    2.107595187962081e-03    3.006883461808889e-03
    1.614089860140201e-02    3.448940307141769e-03    1.391565578928345e-01    1.942847250745000e-03    1.284811218938920e-03
    8.375487333011204e-05    1.019338380076395e-03    2.571184552230859e-04    2.108838820929710e-03    1.234168585070812e-03
    2.040573277497275e-04    2.483478962367943e-03    6.264340545435184e-04    2.107595187962081e-03    3.006883461808888e-03

];

% Partial Turnover Rates - output oriented (CP):

CP = [    -5.710000000000000e+01    0.000000000000000e+00    0.000000000000000e+00    5.220044340306634e+01    0.000000000000000e+00
    0.000000000000000e+00   -3.489999999999999e+01    0.000000000000000e+00    0.000000000000000e+00    3.489970176736618e+01
    6.599997410783703e+00    6.000001555028132e-01   -7.200000000000000e+00    0.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00   -8.040000000000000e+02    3.299945919439816e+02
    2.500019734846110e+00    2.870024525357401e+01    1.500012429370792e+00    5.600091774575834e+02   -5.927000000000000e+02

];

% Storage Analysis - output oriented (SP):

SP = [     1.758970235355222e-02    9.318651156696200e-04    2.350540915588111e-04    1.927886541473388e-03    1.128250290521489e-03
    2.040571948111359e-04    3.113677409130778e-02    6.264338921897977e-04    2.107611717471576e-03    3.006857766944293e-03
    1.614089226923873e-02    3.448941201008303e-03    1.391565578928345e-01    1.942862991698834e-03    1.284800572763778e-03
    8.375416189616180e-05    1.019330385642082e-03    2.571163720655237e-04    2.108838820929710e-03    1.234148359456133e-03
    2.040589385657118e-04    2.483500184740470e-03    6.264392453309453e-04    2.107629727900368e-03    3.006883461808888e-03

];

% Utility series matrix (D):

D = [     0.000000000000000e+00    0.000000000000000e+00   -1.155866900175131e-01    9.141934046071162e-01   -4.378283712784588e-02
    0.000000000000000e+00    0.000000000000000e+00   -1.719197707736390e-02    0.000000000000000e+00    1.776418844517531e-01
    9.166663070532921e-01    8.333335493094628e-02    0.000000000000000e+00    0.000000000000000e+00   -2.083333333333333e-01
   -6.492537313432836e-02    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00   -2.860763781791274e-01
    4.218018786647731e-03   -1.046019022511554e-02    2.530812264840208e-03    3.880701492451213e-01    0.000000000000000e+00

];

% Utility Analysis (U):

U = [     8.617300148717124e-01   -6.047000707111378e-03   -1.000548378431588e-01    7.027959721215685e-01   -2.190117539096227e-01
   -1.615143511925475e-02    9.970192582537089e-01   -1.485211175018589e-02    4.990170799705729e-02    1.666380255832901e-01
    7.915553151818872e-01    7.943599753403145e-02    9.061926655826920e-01    5.782066136781248e-01   -3.747467696903558e-01
   -5.185281332381344e-02    2.993545604639349e-03    5.325116929778573e-03    8.580001577744875e-01   -2.437609346108383e-01
   -1.431551062988679e-02   -9.091774175629451e-03    4.093245162485993e-03    3.368700069247730e-01    9.017883828656738e-01

];

% Control matrix I (CD):

CD = [     0.000000000000000e+00    7.278075977410648e-04   -1.590584447592628e-02    1.844116723172106e-03    9.242006188923809e-04
   -7.278075977410648e-04    0.000000000000000e+00   -2.822506408933382e-03    1.088264517952441e-03    5.233831403064614e-04
    1.590584447592628e-02    2.822506408933382e-03    0.000000000000000e+00    1.685730875084898e-03    6.583719722040907e-04
   -1.844116723172106e-03   -1.088264517952441e-03   -1.685730875084898e-03    0.000000000000000e+00   -8.734540642397653e-04
   -9.242006188923809e-04   -5.233831403064614e-04   -6.583719722040907e-04    8.734540642397653e-04    0.000000000000000e+00

];

% Control matrix II (CR):

CR = [     0.000000000000000e+00    0.000000000000000e+00    9.854373602509098e-01    0.000000000000000e+00    0.000000000000000e+00
    7.810226777261685e-01    0.000000000000000e+00    8.183691695409654e-01    0.000000000000000e+00    0.000000000000000e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00
    9.565561190825564e-01    5.163538086136390e-01    8.676600170358579e-01    0.000000000000000e+00    4.144281755314309e-01
    8.191382448876569e-01    1.740617099784640e-01    5.124270117688579e-01    0.000000000000000e+00    0.000000000000000e+00

];

% Compact NEA matrix (Nea):

Nea = [     0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    5.220042303585520e+01    0.000000000000000e+00    4.900000000000000e+00    9.999996098268557e-01
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    3.489971088678780e+01    0.000000000000000e+00    1.000000261303712e+00
    6.599997424857247e+00    6.000001567822272e-01    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    1.000000002132356e+00
    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    0.000000000000000e+00    3.299972662647558e+02    4.740000000000000e+02    1.000008104135157e+00
    2.499999024567139e+00    2.870000749941653e+01    1.500000003198534e+00    5.600045383156879e+02    0.000000000000000e+00    0.000000000000000e+00    9.999917159538053e-01
    4.799998127168907e+01    5.600001463300787e+00    5.700000012154430e+00    1.918015543731231e+02    2.277981128942769e+02    0.000000000000000e+00    0.000000000000000e+00

];

% Link density (LD):

LD = 1.800000000000000e+00

% Connectance (CON):

CON = 3.600000000000000e-01

% Total system throughflow (TST):

TST = 1.495901592626453e+03

% Finn's Cycling Index (FCI):

FCI = 3.964042129859601e-01

% Indirect effects index (IE):

IE = 1.895436119234820e+00

% Indirect effects index - output oriented (IEP):

IEP = 2.064552092916550e+00

% Ascendency (ASC):

ASC = 1.858374391184044e+03

% Development Capacity (DC):

DC = 5.349039918992583e+03

% Synergism Index (SYN):

SYN = 6.898418805708062e+00

% Mutualism index (MUT):

MUT = 1.500000000000000e+00

%  Aggradation index (AGG):

AGG = 3.123622229794952e+00

% Homogenization index (HM):

HM = 1.851939253362780e+00

% Homogenization index - output based (HMP):

HMP = 2.099750284928490e+00





disp(' ')
disp('You have successfully imported the following EcoNet results:')
disp(' ')
disp(' === VECTOR VALUES === ')
disp(' ')
disp('Environmental inputs (Z):')
disp('Environmental Outputs (Y):')
disp('Initial storage values (IC):')
disp('Final storage values - assumed Steady-state (SS):')
disp('Output throughflow (T):')
disp('Input hroughflow (TP):')
disp('Residence times (RT):')
disp(' ')
disp(' === MATRIX VALUES === ')
disp(' ')
disp('Adjacency Matrix (A):')
disp('Flow Matrix (F):')
disp('Normalized flow matrix (G):')
disp('Throughflow Analysis (N):')
disp('Normalized flow matrix - output oriented (GP):')
disp('Throughflow Analysis - output oriented (NP):')
disp('Partial turnover rate matrix (C):')
disp('Storage Analysis (S):')
disp('Partial Turnover Rates - output oriented (CP):')
disp('Storage Analysis - output oriented (SP):')
disp('Utility series matrix (D):')
disp('Utility Analysis (U):')
disp('Control matrix I (CD):')
disp('Control matrix II (CR):')
disp('Compact Nea matrix (Nea):')
disp(' ')
disp(' === SCALAR VALUES === ')
disp(' ')
disp('Link density (LD):')
disp('Connectance (CON):')
disp('Total system throughflow (TST):')
disp('Finns Cycling Index (FCI):')
disp('Indirect effects index (IE):')
disp('Indirect effects index - output oriented (IEP):')
disp('Ascendency (ASC):')
disp('Development Capacity (DC):')
disp('Synergism Index (SYN):')
disp('Mutualism index (MUT):')
disp('Aggradation index (AGG):')
disp('Homogenization index (HM):')
disp('Homogenization index - output based (HMP):')
disp(' ')