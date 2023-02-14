library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;

entity sc74163_162 is
end sc74163_162;

architecture s74163_162 of sc74163_162 is 
component c74163_162 
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
end component;
  signal mode_s, LdN_s, CLrN_s, P_s, T_s, Clk_s, Cout_s : std_logic := '1'; 
  signal D_s, Qout_s : std_logic_vector(3 downto 0);
  begin 
    S1 : c74163_162 port map (
    mode => mode_s,
    Clk => Clk_s,
    LdN => LdN_s,
    ClrN => ClrN_s,
    P => P_s,
    T => T_s,
    D => D_s,
    Cout => Cout_s,
    Qout => Qout_s
  );
  process begin
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  
  Clk_s <= '0';
  ClrN_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  
  ClrN_s <= '1';
  P_s <= '1';
  T_s <= '1';
  D_s <= "1110";
  LdN_s <= '0';
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  
  LdN_s <= '1';
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  
  mode_s<='0';
  
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  Clk_s <= '1';
  wait for 10 ns;
  Clk_s <= '0';
  wait for 10 ns;
  wait;
  
  end process;
  end s74163_162;
  
  