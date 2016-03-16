% WARNNING : FILE NAME SHOULD BE EQUAL TO FUNCTION NAME


function [ g ] = user_defined_functions( x, y, z, option_ )
if option_ == 1
    g = x.*y + z;
elseif option_ == 2
    g = x + y.*z;
end

end