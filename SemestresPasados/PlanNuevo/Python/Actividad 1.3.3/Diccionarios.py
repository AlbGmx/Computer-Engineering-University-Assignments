grupo = {
    "AVALOS GODOY LEONARDO": 1282003,
    "BECERRA PERAZA ERICK ARTURO ": 1262844,
    "BRAMBILA MOLINA LUIS ADRIAN": 1264791,
    "CASTRO ANTONIO BRANDON ALBERTO": 1284997,
    "DE LA CRUZ CHAVEZ JOSE EDUARDO": 1282778,
    "ESPINO NUÑEZ SHERLYN": 1281160,
    "GUERRA CERVANTES OMAR EDUARDO": 1281859,
    "GUERRA HABANA JOSE GUSTAVO": 1273586,
    "GUTIERREZ SANCHEZ VALERIA KAREY": 1282379,
    "GUTIÉRREZ RUIZ FRANCISCO GABRIEL": 1261897,
    "MACHADO MERAZ ULISES JOEL": 1261836,
    "MENDOZA NAVARRO BRANDON ABRAHAM": 1282292,
    "PINEDA RAMIREZ JAFET JACOB": 1273987,
    "RAMIREZ SANCHEZ ANGEL ALEJANDRO": 1282041,
    "RODRIGUEZ CANDIA VICTOR MANUEL": 1259644,
    "RODRIGUEZ ROSAS LUIS ENRIQUE": 1275919,
    "SANCHEZ ZARAGOZA EDUARDO ARTURO": 1280942,
    "SEGURA SOLIS VALENTINA": 1282007,
    "VELARDE MORALES LUIS EMILIO": 1273159
}

print("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
print("Demostrar que BRAMBILA MOLINA LUIS ADRIAN esta en el grupo")
print("print('BRAMBILA MOLINA LUIS ADRIAN' in grupo)")
print("BRAMBILA MOLINA LUIS ADRIAN" in grupo)

print("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
print("Demostrar que el estudiante cuya matricula es 1272428 no esta en el grupo")
print("print(1272428 not in grupo.values())")
print(1272428 not in grupo.values())

print("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
print("Agregue al estudiante VELZAQUEZ SANCHEZ DIEGO ALEJANDRO 1282923 al grupo\n")
print("grupo['VELZAQUEZ SANCHEZ DIEGO ALEJANDRO'] = 1282923")
grupo["VELZAQUEZ SANCHEZ DIEGO ALEJANDRO"] = 1282923

print("\n\n", grupo)