library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity cdecoder is
port( 
  clk: in std_logic;
  bcd : in std_logic_vector(3 downto 0);
  disp : out std_logic_vector (7 downto 0) -- (ABCDEFG*DP*) --
);							  -- Se toma el punto decimal para completar los 8 bits--
end cdecoder;

architecture bdecoder of cdecoder is 
signal sout : std_logic_vector (7 downto 0) := "00000000";

begin 
  disp <= sout;
  process(clk)
  begin
  	if clk'event and clk='1' then 
    	case bcd is
        	when "0000" => sout <= "11111100";
        	when "0001" => sout <= "01100000";
        	when "0010" => sout <= "11011010";
        	when "0011" => sout <= "01110010";
       	when "0100" => sout <= "01100110";
        	when "0101" => sout <= "10110110";
        	when "0110" => sout <= "10111110"; 
        	when "0111" => sout <= "11100000"; 
        	when "1000" => sout <= "11111110"; 
        	when "1001" => sout <= "11110110"; 
        	default => sout <= "00000000"; -- Cuando se haya introducido algun valor mayor a 9, no habra cambios en el display --
        end case;
  	else sout <= sout;
   end if;
end process; 
end bdecoder;
