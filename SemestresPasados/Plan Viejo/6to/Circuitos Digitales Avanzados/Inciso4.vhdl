// Code your design here
library IEEE;
use IEEE std_logic_1164.all;

entity detector is
port (
  x, clk : in std_logic;
  N : in std_vector (2 downto 0);
  Z : out std_logic
);
end detector;

architecture beh of detector 
signal state : std_logic;
signal remaining : std_vector (2 downto 0);
  begin 
    process (clk)
    begin
      if Clk’event and Clk = ‘1’ then
        if state = '1' and remaining = '0' then
          state <= '0';
          z <= '0';
        elsif state = '0' then 
          state <= '1';
          z <= '1';
          remaining <= N;
        elseif state = '1' then
          remainign <= remaining - 1;
        others remaining <= remaining - 1;
    	end if
      end if
    end process

end beh;