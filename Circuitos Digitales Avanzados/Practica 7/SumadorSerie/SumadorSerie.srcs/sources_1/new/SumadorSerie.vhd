library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

-- SumadorSerie.vhd
entity SumadorSerie is 
    port (
        a,  b, cin  : in std_logic;
        s, cout     : out  std_logic
    );
end SumadorSerie;

architecture Behavioural of SumadorSerie is
begin
    s <= (a xor b) xor (cin);
    cout <= (a and b) or (cin and (a xor b));
end Behavioural;

 