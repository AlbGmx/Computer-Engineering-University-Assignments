// Code your design here
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity registro is
port (
  enr, Clk : in std_logic;
  d_in : in std_vector(7 downto 0);
  q_out : out std_vector(7 downto 0)
);
end registro;

architecture beh of registro 
  begin 
    process (Clk)
    begin
      if Clk’event and Clk = ‘1’ then
        if enr = '1' then
          q_out <= d_in;
        others q_out <= "00000000";
    	end if
      end if
    end process
end beh;

entity contador is
    port(   
      ld, rst, enc, ClK: in std_logic;  
      d_in: in std_logic_vector(7 downto 0);   
      Qout: out std_logic_vector(7 downto 0) 
      ); 
end contador;

architecture behContador of contador is
signal Q: std_logic_vector(7 downto 0); 
signal enCount : std_logic;
begin
  Qout <= Q; 
  enCount <= comparador.comp;
  process (Clk)
  begin
    if Clk’event and Clk = ‘1’ then 
      if rst = '0' then 
        Q <= "00000000";
      elseif ld = '1' then
        Q <= d_in;
      elseif enCount = '1' then
        Q <= Q + 1;
      end if;               
    end if;
end process;
end behContador;

entity comparador is
    port(   
      p, q : in std_logic_vector(7 downto 0);
      comp: out std_logic 
      ); 
end comparador;

architecture behComp is
begin
  if p > q then comp <= "1";
  others comp <= "0";
  end if;  
end process;
end behComp;