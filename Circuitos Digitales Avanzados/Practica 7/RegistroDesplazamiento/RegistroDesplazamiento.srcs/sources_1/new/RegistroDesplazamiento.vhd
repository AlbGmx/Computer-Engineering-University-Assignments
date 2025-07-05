library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity RegistroDesplazamiento is
    generic (
            N : integer := 5  
    );
    port(
            rst, clk, load, d : in std_logic;
            dout 		      : out std_logic;
            din 		      : in std_logic_vector(N-1 downto 0);
            numOut            : out std_logic_vector(N-1 downto 0)
    );
end RegistroDesplazamiento;

architecture Behavioral of RegistroDesplazamiento is
    signal registro : std_logic_vector(N-1 downto 0);
begin
    process(clk, rst)
    begin
        if rst = '1' then
            registro <= (others=>'0');
        elsif rising_edge(clk) then
            if load = '1' then
                registro <= din;
            else
                registro(N-1 downto 1) <= registro(N-2 downto 0);
                registro(0) <= d;
             end if;
         end if;
         numOut <= registro;
         dout <= registro(N-1);
     end process;
end Behavioral;
