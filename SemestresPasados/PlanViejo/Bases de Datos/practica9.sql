Practica 9

inciso 1

DELIMITER !!
CRATE TRIGGER nombre_trigger
BEFORE INSERT ON factura
FOR EACH ROW
BEGIN
   DECLARE fecha_actual DATE;
   DECLARE cant_dias INTEGER;
   DECLARE v_fecha_venta DATE;
   
   -- utilizar funciones de fechas para fecha 
   -- actual y numero de dias
   -- curdate() y datesub() o dateadd()
   
   SELECT fecha INTO v_fecha_venta
   FROM venta
   WHERE folio_venta = NEW.folio_venta;
   
   
   -- utilizar sqlstate 45000 para cancelar
   -- la insercin de la nueva factura


END;

DELIMITER ;


DELIMITER !!
CREATE PROCEDURE nombre_proc(p_folio_venta INTEGER)
BEGIN

DECLARE v_cant_rengolnes INTEGER;
SELECT COUNT(*) INTO v_cant_rengolnes
FROM detalle_venta
WHERE folio_venta = p_folio_venta;
  
SET bloques = v_cant_rengolnes/10;
   
END
DELIMITER ;