library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.STD_LOGIC_ARIT.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity c74194 is 
  port(
  	S0 : in std_logic;
    S1 : in std_logic;
    ClrN : in std_logic;
    Sin_R : in std_logic;
    Sin_L : in std_logic;
    Clk : in std_logic;
    S1 : in std_logic;
    Qin : in std_logic_vector(3 downto 0);
    Qout : out std_logic_vector(3 downto 0)
  );
end c74194;

architecture b74194 of c74194 is
  signal Q : std_vector(3 downto 0);
  
begin 
  process(clk)
  begin 
    if CLrN='0' then
      Q <= "0000";
    elsif clk'event and clk='1' then 
      if S1='1' and S0='1' then
        Q <= Qin;
      elsif S1='1' and S0='0' then
        Q(3) <= Q(2);
        Q(2) <= Q(1);
        Q(1) <= Q(0);
        Q(0) <= Sin_L;
      elsif S1='0' and S0='1' then
        Q(0) <= Q(1);
        Q(1) <= Q(2);
        Q(2) <= Q(3);
        Q(3) <= Sin_R;
      end if;     
    end if;
  end process;
end b74194;