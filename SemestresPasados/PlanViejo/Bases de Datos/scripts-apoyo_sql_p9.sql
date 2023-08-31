Práctica 9:

-- Pregunta 1----------------------------------------------------------------------
DROP TRIGGER venta_reciente;
DELIMITER !!
CREATE TRIGGER venta_reciente
BEFORE INSERT ON factura
FOR EACH ROW
BEGIN
	 DECLARE v_fecha_venta DATE;

	 SELECT fecha INTO v_fecha_venta
	 FROM venta
	 WHERE venta.folio_venta=NEW.folio_venta GROUP BY venta.folio_venta;

	 IF v_fecha_venta < DATE_ADD(CURDATE(), INTERVAL -3 DAY)
	 THEN
		SIGNAL SQLSTATE '45000'
		SET MESSAGE_TEXT = 'La venta no se puede facturar, ya que han pasado mas de 3 dias';
	 END IF; 
END;
DELIMITER ;

-- Pregunta 2 ----------------------------------------------------------------------
CREATE TABLE orden_proveedor (
	id_prov INT,
	codigo VARCHAR(20) COLLATE 'latin2_general_ci'
	fecha_orden DATE NOT NULL,
	cantidad_orden INT NOT NULL,
	PRIMARY KEY (id_prov),
	FOREIGN KEY (codigo) REFERENCES producto(codigo)
);

-- Pregunta 3 ----------------------------------------------------------------------
DELIMITER !!
CREATE TRIGGER re_stock
AFTER INSERT ON detalle_venta
FOR EACH ROW
BEGIN
	DECLARE promCant INT;
	DECLARE cantActual INT;
	SELECT ROUND(AVG(cantidad)) INTO promCant FROM datos_venta WHERE codigo = NEW.codigo;
	SELECT existencia INTO cantActual FROM producto  WHERE codigo= NEW.codigo;
	IF 	cantActual < promCant 
	THEN
		INSERT INTO orden_proveedor(codigo, fecha_orden, cantidad_orden) VALUES (NEW.codigo, CURDATE(), NEW.cantidad);
	END IF;
END;
DELIMITER ;

-- Pregunta 4 ----------------------------------------------------------------------
DROP PROCEDURE div_venta;
DELIMITER !!
CREATE PROCEDURE div_venta(p_folio_venta INTEGER)
BEGIN

	DECLARE v_cant_renglones INTEGER;
	DECLARE og_date DATE;
	DECLARE maxFolio INT;

	-- contar los renglones de la venta'
	SELECT count(*) INTO v_cant_renglones FROM detalle_venta WHERE folio_venta=p_folio_venta;
	SELECT fecha INTO og_date FROM venta WHERE folio_venta = p_folio_venta;
	--Si hay más de 10 renglones, Inserta una nueva venta y MODIFICA el folio venta de los primeros 10 registros a ese nuevo
	IF v_cant_renglones  > 10
	THEN
		INSERT INTO venta VALUES (null, og_date); 
		SELECT max(folio_venta) INTO maxFolio FROM venta;
		UPDATE detalle_venta 
		SET folio_venta = maxFolio
		WHERE folio_venta = p_folio_venta
		LIMIT 10;

		--Una vez terminados los 10 primeros, cuenta si hay más de 10 con el mismo folio, entonces se llama a sí misma
		SELECT count(*) INTO v_cant_renglones FROM detalle_venta WHERE folio_venta=p_folio_venta;
		IF v_cant_renglones  > 10 
		THEN
			call div_venta(p_folio_venta);
		END IF;
	END IF;
END;
DELIMITER ;


-- COMO SE EJECUTA EL PROCEDIMIENTO

CALL nombre_proc(20000);

-- Pregunta 5 ----------------------------------------------------------------------
DROP TRIGGER split_for_invoice;
DELIMITER !!
CREATE TRIGGER split_for_invoice
BEFORE INSERT ON factura
FOR EACH ROW
BEGIN
	DECLARE v_cant_renglones INT;
	SELECT count(*) INTO v_cant_renglones FROM detalle_venta WHERE folio_venta=NEW.folio_venta;
	IF 	v_cant_renglones > 10  
	THEN
		CALL div_venta(NEW.folio_venta);
		SIGNAL SQLSTATE '45000'
		SET MESSAGE_TEXT = 'No se puede facturar ya que la venta tiene mas de 10 registros';
	END IF;
END;
DELIMITER ;

--El código funciona pero revierte lo que se hace por utilizar SIGNAL SQLSTATE
--Por lo que el cambio de div_venta no se verá reflejado
--Así que una solución es no impedir la factura, hacerla después de haber dividido la venta
--O no llamar a la función

DROP TRIGGER split_for_invoice;
DELIMITER !!
CREATE TRIGGER split_for_invoice
BEFORE INSERT ON factura
FOR EACH ROW
BEGIN
	DECLARE v_cant_renglones INT;
	SELECT count(*) INTO v_cant_renglones FROM detalle_venta WHERE folio_venta=NEW.folio_venta;
	IF 	v_cant_renglones > 10  
	THEN
		CALL div_venta(NEW.folio_venta);
	END IF;
END;
DELIMITER ;










