Library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity c_calentador is 
PORT( 
	clk, switch, flow, temp, fire : in std_logic;
  	sparke, flow : out std_logic
);
end c_calentador;

architecture b_calentador of c_calentador is 
component c_timer port(
	clk,rst : in std_logic;
    time : out std_logic
);
end component;
 
signal reset : std_logic := '0';
signal t : std_logic :='0';
signal estado : states; 
type states is (s0,s1,s2,s3,s4,s5);

begin 
  t1 : c_timer port map (
  	clk => clk, 
  	rst => reset,
  	time => t
  ); 
  process(clk)
  begin
    if clk'event and clk='1' then 
      case estado is 
        
        when s0 => 
          if switch='1' then 
            estado<=s1;
          end if;
        
        when s1 =>
          if flow='1' then 
            estado<=s2;
          elsif switch='0' then 
            estado<=s0;
          end if;
        when s2 =>
          if t='1' then 
            estado<=s3;
          elsif fire='1' then
            estado<=s4;
          elsif flow='0' then
            estado<=s1;
          end if;
        
        when s3 =>
          if flow='0' then 
            estado<=s1;
          end if;
                    
        when s4 => 
          if temp='1' then 
            estado<=s5;
          elsif flow='0'then 
        	estado<=s0;
          end if;

        when s5 => 
          if temp='0' or flow='0' then 
            estado<=s0;
          end if;
        
        end case;     
    end if;
  end process;
  spark <= '1' when estado=s2 else '0';
  valve <= '1' when estado=s2 or estado=s4 else '0';
  reset <= '1' when estado=s2 else '0';

end b_calentador;

entity c_timer is 
port(
	clk,rst : in std_logic;
    time : out std_logic
    );
end c_timer;

architecture b_timer of c_timer is 
    signal ticks : integer;
begin 
	process(clk)  
    begin
    	if clk'event and clk='1' then
          if rst='0' then 
          	ticks<='0';
            time <='0';
          else 
          	if ticks = 8000000-1 then 
              ticks <= 0;
              time <= '1';
            else 
              ticks <= ticks + 1;
              time<='0';
            end if;
          end if;
        end if;
    end process;
end b_timer;