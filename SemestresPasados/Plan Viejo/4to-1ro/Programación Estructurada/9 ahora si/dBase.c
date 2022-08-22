/*
  practica 9 Programación Estructurada							Gómez Cárdenas Emmanuel Alberto
  21/11/2019																		                          Grupo 531
  
  Este programa cuenta con funciones para el manejo de  registro de anuncios con el que
  se pueden registrar, editar y eliminar anuncios. Se pueden mostrar los anuncios ya 
  registrados por diferentes filtros, se hace uso de la biblioteca time.h para mostrar
  aquellos anuncios que fueron registrados con fechas de publicacion anteriores a la
  fecha actual del sistema y por ultimo, se puede crear un respaldo de los datos registrados
  en formato csv (comma separated values o valores separados por coma) el cual puede ser 
  visualizado en excel.
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CLEAR() system("CLS")
#define CLASS 1
#define RESP 2
#define DATE 3
#define SHOW 1
#define HIDE 0
struct fecha{
  int day;
  int month;
  int year;  
  int flag;
};
struct anuncio{
  int ID;
  char class[20];
  char resp[20];
  char phone[20];
  char cont[50];
  struct fecha date;
};
void captura(struct anuncio *, char*);
void grabar(struct anuncio, char*);
void mostrar(int, char*, char*);
int compare (int, char*);
void borrar(char*);
void editar(char*);
void ordenar(int, char*);
long int tamano(FILE *);
void printReg(struct anuncio);
void getClass(struct anuncio*);
void getDate(struct anuncio*);
void consultBy(int,  char*);
void update(char*);
int checkDate(struct anuncio, char*);
void selectEditReg(struct anuncio*,  char*);
void editReg(int, struct anuncio*,  char*);
void backup(char*);


int main(int arg, char *argv[]){
  struct anuncio reg;
  char opc;
  if(arg<2){
    printf("Faltan parametros ");
    exit(-1);
    }
  do{
    update(argv[1]);
    CLEAR();
    puts("1) Registrar anuncio");
    puts("2) Cancelar anuncio");
    puts("3) Editar anuncio");
    puts("4) Consultar por clasificacion");
    puts("5) Consultar por responsable");
    puts("6) Ordenar por responsable");
    puts("7) Mostrar todos los anuncios que se publicaran en la fecha actual del sistema");
    puts("8) Generar respaldo de los datos");
    puts("9) Salir");
    printf("Opcion:");
    setbuf(stdin, 0);
    opc=getchar();
    switch(opc){
      case '1': captura(&reg, argv[1]);  grabar(reg, argv[1]);  break;
      case '2': borrar(argv[1]); break;
      case '3': editar(argv[1]); break;
      case '4': consultBy(CLASS, argv[1]); break;
      case '5': consultBy(RESP, argv[1]);  break;
      case '6': ordenar(RESP, argv[1]); mostrar(0, "0", argv[1]); break;
      case '7': mostrar(DATE, "0", argv[1]); break;
      case '8': backup(argv[1]); break;//save(); break;
    }
  }while (opc!=57 && opc!=48);
  return 0;
}
void captura(struct anuncio *reg, char *dBase){   
    int num;
    printf("ID de anuncio: "); scanf("%d",&num);
    setbuf(stdin,0);
    if(compare(num, dBase)==-1){
      reg->ID = num;
      getClass(reg);
      printf("Responsable de la publicacion: ");      gets(reg->resp);
      printf("Telefono del responsable: ");           gets(reg->phone);
      printf("Contenido del anuncio: ");              gets(reg->cont);    
      getDate(reg);              
   }else printf("ID ya utilizado o invalido");
    getchar();
}
void grabar(struct anuncio reg, char *dBase){
  FILE * flujo;
  flujo= fopen(dBase,"ab");
  if (flujo!=NULL){
    fwrite(&reg,sizeof(struct anuncio),1,flujo);
    fclose(flujo);
  }
  else  printf("No se pudo abrir");
}
void mostrar(int show, char* str, char *dBase){
  CLEAR();
  FILE * flujo;
  struct anuncio reg;
  time_t fecha_actual = time(NULL);
  struct tm fecha = *localtime(&fecha_actual);
  const char *month[]={"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
  int cont=1;
  flujo= fopen(dBase,"rb");
  if (flujo){
    switch(show){
      case 0:
        while( fread(&reg,sizeof(struct anuncio),1,flujo)>0){
          printReg(reg);
          setbuf(stdin,0);
          getchar();
          cont++;
        }
      break;
      case CLASS: 
        while( fread(&reg,sizeof(struct anuncio),1,flujo)>0){
          if(strcmpi(reg.class, str)==0){
            printReg(reg);
            setbuf(stdin,0);
            getchar();
            cont++;
          }
        }
        if(cont==1) cont=-30;
      break;
      case RESP:
        while(fread(&reg,sizeof(struct anuncio),1,flujo)>0){
          if(strcmpi(reg.resp, str)==0){
            printReg(reg);
            setbuf(stdin,0);
            getchar();
            cont++;
          }
        }
        if(cont==1) cont=-20;
      break;
      case DATE:
        while(fread(&reg,sizeof(struct anuncio),1,flujo)>0){
          if(reg.date.flag==SHOW){
            printReg(reg);
            setbuf(stdin,0);
            getchar();
            cont++;
          }
        }
        if (cont-2==-1){
          puts("Aun no existen anuncios que deban ser publicados a la fecha actual");
          printf("Fecha actual del sistema: %d de %s del a\244o %d\n", fecha.tm_mday, month[fecha.tm_mon], fecha.tm_year+1900);
          setbuf(stdin,0);
          getchar();
          setbuf(stdin,0);
          cont+=20;
        }
      break;
    }
    if (cont-2==-1){
      printf("Aun no existen registros");
      setbuf(stdin,0);
      getchar();
      setbuf(stdin,0);
    }
    else if (cont==-20){
      printf("Aun no existen registros de %s", str);
      setbuf(stdin,0);
      getchar();
      setbuf(stdin,0);
    }
    else if (cont==-30){
      printf("Aun no existen registros de clasificacion %s", str);
      setbuf(stdin,0);
      getchar();
      setbuf(stdin,0);
    }
    fclose(flujo);
  }
}
int compare (int num, char* dBase){
  FILE * flujo;
  struct anuncio reg;
  int cont=0;
  flujo = fopen(dBase,"rb");
  if (flujo){
    while( fread(&reg,sizeof(struct anuncio),1,flujo)>0){
      cont++;
      if (reg.ID==num){
        fclose(flujo);
        return cont;
      }
    }
    fclose(flujo);
  }
  return -1;
}
void editar(char* dBase){
  int ban;
  int num;
  struct anuncio reg;
  FILE * flujo;
  setbuf(stdin,0);
  printf("Id del anuncio: "); scanf("%d", &num);
  ban=compare(num, dBase);
  CLEAR();
  if (ban!=-1){
    flujo= fopen(dBase,"rb+");
    if (flujo!=NULL){
      fseek(flujo,(ban-1)*sizeof(struct anuncio),SEEK_SET);
      fread(&reg,sizeof(struct anuncio),1,flujo);
      selectEditReg(&reg, dBase);
      fseek(flujo,(ban-1)*sizeof(struct anuncio),SEEK_SET);
      fwrite(&reg,sizeof(struct anuncio),1,flujo);
      fclose(flujo);
    }
    else  {
      printf("No se pudo abrir el archivo %s", dBase);
      setbuf(stdin,0);
      getchar();
    }
  }
  else{
    printf("No se ha encontrado anuncio con ID %d", num);
    setbuf(stdin,0);
    getchar();
  }
}
void borrar(char *dBase){
  FILE *original, *copia;
  int num,i;
  int ban;
  struct anuncio aux;
  original=fopen(dBase,"rb");
  copia=fopen("temporal.dat","wb");
  if (!original || !copia){
    printf("No se pudo abrir el archivo %s", dBase);
    setbuf(stdin,0);
    getchar();
  }
  else{
    printf("ID del anuncio que desea eliminar: ");
    setbuf(stdin, 0);
    scanf("%d", &num);
    ban=compare(num, dBase);
    if (ban!=-1){
      while(fread(&aux,sizeof(struct anuncio),1,original)>0){
        if(num!=aux.ID) fwrite(&aux,sizeof(struct anuncio),1,copia);
      }
      fclose(original);
      fclose(copia);
      remove(dBase);
      rename("temporal.dat", dBase);
      printf("\nBorrando");
      for(i=0; i<100000000; i++); printf(".");
      for(i=0; i<100000000; i++); printf(".");
      for(i=0; i<100000000; i++); printf(".");
      printf("\n\nListo\n");     
    }
    else puts("No se encontro el anuncio");
    getchar();
  }
}
void ordenar(int sort, char *dBase){
  FILE *flujo;
  int i=0, j, n;
  struct anuncio a,b;
  flujo=fopen(dBase,"rb+");
  if (flujo==NULL) printf("No se pudo abrir el archivo %s", dBase);
  else{       
    n=tamano(flujo)/sizeof(struct anuncio);
    for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){
      if (sort){
        fseek(flujo,i*sizeof(struct anuncio),SEEK_SET);
        fread(&a,sizeof(struct anuncio),1,flujo);
        fseek(flujo,j*sizeof(struct anuncio),SEEK_SET);
        fread(&b,sizeof(struct anuncio),1,flujo);
        if(strcmpi(a.class,b.class)>0){
          fseek(flujo,i*sizeof(struct anuncio),SEEK_SET);
          fwrite(&b,sizeof(struct anuncio),1,flujo);
          fseek(flujo,j*sizeof(struct anuncio),SEEK_SET);
          fwrite(&a,sizeof(struct anuncio),1,flujo);
        }
      }
      else{
        fseek(flujo,i*sizeof(struct anuncio),SEEK_SET);
        fread(&a,sizeof(struct anuncio),1,flujo);
        fseek(flujo,j*sizeof(struct anuncio),SEEK_SET);
        fread(&b,sizeof(struct anuncio),1,flujo);
        if(strcmpi(a.resp,b.resp)>0){
          fseek(flujo,i*sizeof(struct anuncio),SEEK_SET);
          fwrite(&b,sizeof(struct anuncio),1,flujo);
          fseek(flujo,j*sizeof(struct anuncio),SEEK_SET);
         fwrite(&a,sizeof(struct anuncio),1,flujo);
        }
      }
    }
  fclose(flujo);
  }
}                                     
long int tamano(FILE *file){
  char buffer;
  long int size=0;
  fseek(file, 0, SEEK_SET);
  while(fread(&buffer, 1, 1, file)>0)size++;
  fseek(file, 0, SEEK_SET);
  return size;
}
void printReg(struct anuncio reg){
  const char *month[12]={"ENE", "FEB", "MAR", "ABR", "MAR", "JUN", "JUL", "AGO", "SEP","OCT", "NOV", "DIC"};
  printf("Numero de identificacion del anuncio: %d\n", reg.ID);
  printf("Clasificacion del anuncio: ");          puts(reg.class);
  printf("Responsable de la publicacion: ");      puts(reg.resp);
  printf("Telefono del responsable: ");           puts(reg.phone);
  printf("Contenido del anuncio: ");              puts(reg.cont);    
  printf("Fecha de publicacion: %d/%s/%d\n", reg.date.day, month[reg.date.month], reg.date.year);              
}
void getClass(struct anuncio *reg){
  int aux, flag=1;
  do{
    CLEAR();
    puts("Clasificacion del anuncio: ");
    puts("1) Autos");
    puts("2) Empleos");
    puts("3) Mascotas");
    puts("4) Renta");
    puts("5) Traspasos");
    puts("6) Venta varios");
    puts("7) Otros");
    printf("Opcion:");
    setbuf(stdin, 0);
    aux=getchar();
    setbuf(stdin,0);
    setbuf(stdin,0);
    setbuf(stdin,0);
    setbuf(stdin,0);
    setbuf(stdin,0);
    setbuf(stdin,0);
    if(aux>'0' && aux<'8'){
      switch(aux){
        case '1':  strcpy(reg->class, "Autos"); break;
        case '2':  strcpy(reg->class, "Empleos"); break;
        case '3':  strcpy(reg->class, "Mascotas"); break;
        case '4':  strcpy(reg->class, "Renta"); break;
        case '5':  strcpy(reg->class, "Traspasos"); break;
        case '6':  strcpy(reg->class, "Venta varios"); break;
        case '7':  strcpy(reg->class, "Otros"); break;
      }
      flag=0;
    }
    else{
      puts("Por favor introduzca un numero menor a 8 y mayor a 0");
      getchar();
    }
  }
  while (flag!=0);
}
void getDate(struct anuncio *reg){
  int flag;
  do{
    flag=0;
    puts("Fecha de publicacion del anuncio (DD/MM/AAAA):");
    scanf("%d/%d/%d", &reg->date.day, &reg->date.month, &reg->date.year);
    reg->date.month-=1;
    if(reg->date.year<2000 || reg->date.year>2100) puts("Porfavor introduza un a\244o mayor a 2000 y menor a 2100");
    else if(reg->date.month<0 || reg->date.month>13) puts("Porfavor introduza un mes mayor a 0 y menor a 13");
    else if(reg->date.day > 28 && reg->date.month== 2){
      puts("Consejo: Febrero solo tiene 28 dias...");
      setbuf(stdin,0);
      setbuf(stdin,0);
      setbuf(stdin,0);
      getchar();
      flag=1;
    }
    else if(reg->date.day == 31){
      if(reg->date.month == 2 || reg->date.month == 4 || reg->date.month == 6 || reg->date.month == 9 || reg->date.month==11)     
        puts("Al parecer hubo un error con las fechas, favor de corregirlas");
        setbuf(stdin,0);
        setbuf(stdin,0);
        setbuf(stdin,0);
        getchar();
        flag=1;
    } 
  }while(flag!=0);
}
void consultBy(int select, char *dBase){
  int aux, flag=1;
  char* str;
  if(select==CLASS){
    do{
      CLEAR();
      puts("Seleccionar la categoria del anuncio a mostrar: ");
      puts("1) Autos");
      puts("2) Empleos");
      puts("3) Mascotas");
      puts("4) Renta");
      puts("5) Traspasos");
      puts("6) Venta varios");
      puts("7) Otros");
      printf("Opcion:");
      setbuf(stdin, 0);
      aux=getchar();
      setbuf(stdin,0);
      setbuf(stdin,0);
      setbuf(stdin,0);
      setbuf(stdin,0);
      setbuf(stdin,0);
      setbuf(stdin,0);
      if(aux>'0' && aux<'8'){
        switch(aux){
          case '1':  mostrar(CLASS, "Autos", dBase); break;    
          case '2':  mostrar(CLASS, "Empleos", dBase); break;  
          case '3':  mostrar(CLASS, "Mascotas", dBase); break;  
          case '4':  mostrar(CLASS, "Renta", dBase); break;    
          case '5':  mostrar(CLASS, "Traspasos", dBase); break;  
          case '6':  mostrar(CLASS, "Venta varios", dBase); break;  
          case '7':  mostrar(CLASS, "Otros", dBase); break;    
        }
        flag=0;
      }
      else{
        puts("Por favor introduzca un numero menor a 8 y mayor a 0");
        getchar();
      }
    }
    while (flag!=0);
  }    
  else if(select==RESP){
    char aux[20];
    printf("Nombre del usuario a buscar: ");
    setbuf(stdin, 0);
    scanf("%s", aux);
    mostrar(RESP, aux, dBase);
  }
}  
void update(char *dBase){
  struct anuncio reg;
  FILE * flujo;
  int i;
  flujo = fopen(dBase,"rb+");
  if (flujo!=NULL){
    for(i=0; i<tamano(flujo)/sizeof(struct anuncio); i++){ 
      fseek(flujo,i*sizeof(struct anuncio),SEEK_SET);
      fread(&reg,sizeof(struct anuncio),1,flujo);
      reg.date.flag=checkDate(reg, dBase);
      fseek(flujo,i*sizeof(struct anuncio),SEEK_SET);
      fwrite(&reg,sizeof(struct anuncio),1,flujo);
    }
      fclose(flujo);
  }
}
int checkDate(struct anuncio reg, char *dBase){
  time_t fecha_actual = time(NULL);
  struct tm fecha = *localtime(&fecha_actual);
  if(reg.date.year != fecha.tm_year+1900){
    if(reg.date.year > fecha.tm_year+1900) return HIDE;
    else if(reg.date.year < fecha.tm_year+1900) return SHOW;
  } 
  else if(reg.date.year = fecha.tm_year+1900){
    if(reg.date.month > fecha.tm_mon) return HIDE;
    else if(reg.date.month < fecha.tm_mon) return SHOW;
    
    else if(reg.date.month == fecha.tm_mon){
      if(reg.date.day > fecha.tm_mday) return HIDE;
      else if(reg.date.day < fecha.tm_mday) return SHOW;
      else if(reg.date.day == fecha.tm_mday) return SHOW;
    }
  }
  return 1;
}
void selectEditReg(struct anuncio *reg, char* dBase){
  int aux;
  char flag='y';
  do{
    CLEAR();
    printReg(*reg);
    puts("\n\nSeleccionar el modulo del anuncio a editar (el ID no se puede editar): ");
    puts("\t1) Clasificacion");
    puts("\t2) Responsable");
    puts("\t3) Telefono del responsable");
    puts("\t4) Contenido del anuncio");
    puts("\t5) Fecha de publicacion");
    puts("\t6) Cancelar");
    printf("Opcion:");
    setbuf(stdin, 0);
    scanf("%d", &aux);
    if(aux>0 && aux<6) editReg(aux, reg, dBase); 
    if(aux!=6){
      puts("Desea seguir editando el anuncio (y/n)?");
      setbuf(stdin,0);
      flag=getchar();
    }
    else flag = 'n';

  }
  while (aux != '0' && aux != '6' && flag == 'y');
}
void editReg(int aux, struct anuncio *reg, char *dBase){
  const char *month[12]={"ENE", "FEB", "MAR", "ABR", "MAR", "JUN", "JUL", "AGO", "SEP","OCT", "NOV", "DIC"};
  switch(aux){
    case 1: 
      printf("Clasificacion actual: %s", reg->class);
      getchar();
      getClass(reg);
      break;
    case 2: 
      printf("Responsable actual: %s\n", reg->resp);
      printf("Nuevo responsable: ");  scanf("%s", reg->resp);     
      break;
    case 3: 
      printf("Telefono actual: %s\n", reg->phone);
      printf("Nuevo telefono: ");  scanf("%s", reg->phone);     
      break;
    case 4: 
      printf("Contenido del anuncio actual: %s\n", reg->cont);
      printf("Nuevo contenido del anuncio: ");  scanf("%s", reg->cont);     
      break;
    case 5: 
      printf("Fecha de publicacion: %d/%s/%d\n", reg->date.day, month[reg->date.month], reg->date.year);              
      getDate(reg);
      break;
  }
}
void backup(char *dBase){
  CLEAR();  
  struct anuncio a;
  FILE *flujo=NULL, *filePtr=NULL;
  char csv[20];
  puts("Introduce el nombre del respaldo");
  scanf("%s", csv);
  flujo=fopen(dBase, "rb");
  filePtr=fopen(csv, "w ");
  if(!flujo || !filePtr) {
    printf("No se pudo abrir el archivo %s o %s\n", dBase, csv); 
    setbuf(stdin,0);
    getchar();
  }
  else{
    fprintf(filePtr,"%s,%s,%s,%s,%s,%s\n", "ID", "Clasificacion", "Responsable", "Telefono", "Contenido", "Fecha de publicacion (DD/MM/AAAA)");
    while(fread(&a,sizeof(struct anuncio),1,flujo)>0){
      fprintf(filePtr,"%d,\"%s\",\"%s\",\"%s\",\"%s\",%d/%d/%d\n", a.ID, a.class, a.resp, a.phone, a.cont, a.date.day, a.date.month+1, a.date.year);
    }
  }
  fclose(filePtr);
  fclose(flujo);
}