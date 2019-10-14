// ************************************* GAS SENSOR *************************************************
void ReadSSI(void)
{
  soma_temp = 0;
  
  // A definição do valor da variável gas_level é feita a partir de 51 amostras de gas_level_vector
  // com posterior implementação de um Filtro Média Móvel por Convolução Recursivo

  if (f_vez == 0)
  {
     for(indice=0;indice<51;indice++)
     {
        gas_level_vector[indice] = 0;
     }

     f_vez = 1;

     for(indice=0;indice<51;indice++)
     {
        soma_temp = soma_temp + gas_level_vector[indice];
     }

      gas_level = soma_temp / 51;

      soma_temp = 0;
  }  
  else
  {
    for(indice=0;indice<50;indice++)
    {
      gas_level_vector[indice] = gas_level_vector[indice+1];
    }

    indice = 50;

    gas_level_vector[indice] = 0;

    for(indice=0;indice<51;indice++)
    {
      soma_temp = soma_temp + gas_level_vector[indice];
    }

    gas_level = soma_temp / 51;

    soma_temp = 0;
  }
        
  Serial.println("\n\nNível de Gás: ");
  Serial.println(gas_level,DEC);
  Serial.println("\n\n");
}
// ************************************* END GAS SENSOR *******************************************************

