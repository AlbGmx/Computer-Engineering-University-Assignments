-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;

entity cSteam_boiler is 
port(
	clk, steam_press, air,  fire, switch, reset, t : in std_logic;
    spark, pilot_valve, main_valve, fail, motor : out std_logic
    );
end cSteam_boiler;

architecture bSteam_boiler of cSteam_boiler is 
-- Registro de estados
type states is (s0, s1, s2, s3, s4, s5, s6, s7);
signal estado : states;
begin 
	process(clk)
      if clk'event and clk='1' then
 		-- Si el switch esta apagado, apagar todo sin importar el estado actual
		if switch ='0' then 
          estado <= s0;
        -- Logica de estados
	    case estado is 
		  when s0 => 
            if switch='1' then 
              estado <= s1;
            end if;
          when s1 =>
            if steam_press='0' then 
              estado <= s2
            elsif switch='0' then 
              estado <= s0;
            end if;
          when s2 =>
            if t='1' then
              estado <= s4;
            elsif air='1' then
              estado <= s3;
            end if;
          when s3 =>
            if t='1' then 
              estado <= s5;
            elsif fire='1' then
              estado <= s6;
            end if;
          when s4 =>
            if reset='1' then
              estado <= s1;
            end if;
          when s5 =>
            if t='1' then 
              estado <= s4;
            end if;
          when s6 =>
            if t='1' then 
              estado <= s7;
            end if;
          when s7 =>
            if air='0' or fire ='0' then 
              estado <= s4;
            elsif steam_press='1' then
              estado <= s1;
            end if;
		end case;
	  end if;
    begin 
    end process;
    
    -- Logica de salidas
    spark <= '1' when estado=s6 or estado=s3 else '0';
    pilot_valve <= '1' when estado=s3 or estado=s6 else '0';
    main_valve <= '1' when estado=s6 else '0';
    fail <= '1' when estado=s4 else '0';
    motor <= '1' when estado=s2 or estado=s3 or estado=s5 or estado=s6 or estado=s7;
 
end bSteam_boiler;