library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity cControl is
port(   
  load, shr, clk,done :  out std_logic;
  start, m : in std_logic;

end cControl;

architecture bControl of cControl is
 type states is (s0, s1, s2, s3, s4);
 signal estado : states;
 signal counter : std_logic_vector(2 downto 0);

 
begin
  process (clk)
  begin
  case estado is 
    when s0 => 
      if st='1' then 
        estado <= s1;
        counter <= "100";
      end if;
    when s1 => 
      if m='1' then 
        estado <= s2;
      else estado <= s3;
      end if;
    when s2 => 
      estado <= s3;
    when s3 => 
      estado <= s1
      counter <= counter - 1;
      if counter="000" then 
        estado <= s4;
      end if;
    when s4 =>
      estado <= s0;

  end process;
  load <= '1' when estado=s1 else '0'; 
  shr <= '1' when estado=s3 else '0';
  add <= '1' when estado =s2 else '0';
  done <= '1' when estado=s4 else '0';
end bControl;