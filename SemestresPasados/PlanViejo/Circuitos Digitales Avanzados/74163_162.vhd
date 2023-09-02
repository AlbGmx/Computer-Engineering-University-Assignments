library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;

entity c74163_162 is 
  port(
  	mode : in std_logic;
    LdN : in std_logic;
    ClrN : in std_logic;
    P,T : in std_logic;
    Clk : in std_logic;
    D : in std_logic_vector(3 downto 0);
    Cout : out std_logic;
    Qout : out std_logic_vector(3 downto 0)
  );
end c74163_162;

architecture b74163_162 of c74163_162 is
  signal Q : std_logic_vector(3 downto 0);
  
begin 
  Qout <= Q;
  Cout <= Q(3) and Q(2) and Q(1) and Q(0) and T;
  process(clk)
  begin 
    if Clk'event and Clk='1' then 
      if ClrN='0' then 
        Q <= "0000";
      elsif LdN='0' then 
        Q <= D; 
      elsif P='1' and T='1' then
        if mode='1' then
          if Q = 1001 then
            Q <= "0000";
          elsif Q=1011 or Q=1101 then
            Q<="0100";
          else Q <= Q + 1;
          end if;
        elsif mode='0' then
          if Q = 1111 then
            Q<="0000";
          else 
            Q <= Q + 1;
		  end if;
	    end if;
      end if;
    end if;
  end process;
end b74163_162;