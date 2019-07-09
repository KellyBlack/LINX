function m = FII(S,fk,fi)
% m = FII(S) computes the Flow Importance Index of each flow of an
% ecosystem model with the stoichiometric matrix S. Adjacency matrix
% may be used instead of the stoichiometric matrix, by converting it to
% the stoichiometric matrix using the code A2S.m provided along with
% this function. 
%
% m = FII(S,fk,fi) computes the Flow Importance Index of each flow
% for an ecosystem model with the stoichiometric matrix S, where fk
% is a vector containing the flows that are already determined 
% (fk stands for Flows Known) and fi is a vector containing the flows
% that are not feasible to determine (fi stands for Flows Infeasible.)
%
% If EcoNet (http://eco.engr.uga.edu) is used as modelling software, this 
% code may be directly executed after downloading and executing the
% Matlab code automatically generated by EcoNet as follows:
%
% EcoNet_Results;
% m = FII(SM);

if ( nargin == 1 )
  fk=[];
  fi=[];
elseif ( nargin ~= 3 )
  help FII
  return
end

if ( length(find( S~=-1 & S~=0 & S~=1 )) ~= 0 ) 
  fprintf('\n Stoichiometric matrix can only take values -1, 0 and 1!\n\n');
  return
end
  
n = size(S,1); % number of compartments
k = size(S,2); % number of flows
Nfk = size(fk,2);
Nfi = size(fi,2);

% flow indices that are not "known or unknown"
k_ind = setdiff(1:k,[fk fi]); % actual flow indices
Ksubsets = combnk(k_ind,n-Nfi);
nKsubsets = size(Ksubsets,1); % number of k subsets
% number of subsets of size k inlcuding flow i
nKsubsets_i = nKsubsets*(k-n-Nfk)/(k-Nfi-Nfk);

Nfeas = 0; % number of feasible k subsets 
% number of feasible k subsets inlcuding flow i
Nfeas_i = zeros(1,k); 
% Conditions sum of feasible k subsets including i
sum_cond = zeros(1,k); 
% Sum of inverse conditions of feasible k sub...
sum_invcond = zeros(1,k); 

for i = 1:nKsubsets 
  if ( rank(S(:,[Ksubsets(i,:) fi])) == n )
    Nfeas = Nfeas + 1;
    conditions( Nfeas ) = cond(S(:,[Ksubsets(i,:) fi]));
    for j = setdiff(k_ind,Ksubsets(i,:))
      Nfeas_i(j) = Nfeas_i(j) + 1;
      sum_cond(j) = sum_cond(j) + conditions( Nfeas );
      sum_invcond(j) = sum_invcond(j)+1/conditions( Nfeas );
    end
  end  
end

m = sum_invcond'/max(sum_invcond');
m(fk,:) = -1; % set known flows to -1
m(fi,:) = -2; % set unknown flows to -2

format compact
disp('Number  Flow      FII (-1:known -2:infeasible):');
flow_type = sum(S);
for i=1:k
  if ( flow_type(i) == 0 )
    f_from = find( S(:,i) == -1 );
    f_to = find( S(:,i) == 1 );
    fprintf('%3i     %i -> %i    %.4f\n', i, f_from, f_to, m(i));
  elseif ( flow_type(i) == 1 )
    f_to = find( S(:,i) == 1 );
    fprintf('%3i     * -> %i    %.4f\n', i, f_to, m(i));
  elseif ( flow_type(i) == -1 )
    f_from = find( S(:,i) == -1 );
    fprintf('%3i     %i -> *    %.4f\n', i, f_from, m(i));
  end
end