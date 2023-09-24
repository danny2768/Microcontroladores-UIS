int  x = 200;
#define pacman 2

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);


byte smile1[8] =              // Vetor do caracter especial smile
{
  0b00000,
  0b11011,
  0b11011,
  0b00100,
  0b00100,
  0b10001,
  0b01110,
  0b00000
},
smile2[8] =              // Vetor do caracter especial smile 2
{
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
},
ghost1[8] =              // Vetor do caracter especial
{
  0b00000,
  0b01110,
  0b11111,
  0b10101,
  0b11111,
  0b11111,
  0b10101,
  0b00000
},
ghost2[8] =              // Vetor do caracter especial
{
  0b00000,
  0b01110,
  0b11111,
  0b10101,
  0b11111,
  0b11111,
  0b01010,
  0b00000
},
pacman1[8] =              // Vetor do caracter especial
{
  0b01110,
  0b11011,
  0b11100,
  0b10000,
  0b11100,
  0b11111,
  0b01110,
  0b00000
},
pacmanb[8] =              // Vetor do caracter especial
{
  0b00000,
  0b01110,
  0b11011,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00000
},
pastilha[8] =              // Vetor do caracter especial
{
  0b00000,
  0b00000,
  0b00100,
  0b01110,
  0b01110,
  0b00100,
  0b00000,
  0b00000
},
pacmanv[8] =              // Vetor do caracter especial
{
  0b01110,
  0b11011,
  0b00111,
  0b00001,
  0b00111,
  0b11111,
  0b01110,
  0b00000
};

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(5, 0);
  lcd.print("PACMAN");
  lcd.setCursor(2, 1);
  lcd.print("Nery & Daniel");
  delay(2000);
  lcd.clear();
  
  lcd.createChar(0, ghost1);         
  lcd.createChar(1, ghost2);         
  lcd.createChar(pacman, pacman1);         
  lcd.createChar(3, pacmanb);         
  lcd.createChar(4, pastilha);        
  lcd.createChar(5, pacmanv);
  lcd.begin(16, 2);                  
}

void loop()
{
  int tempo = 150,i;
  byte g = 0, f, e = 15;
  for (i = 16; i >=0 ; i--)
  {
    
    for (f = g; f < 16; f++)
    {
      lcd.setCursor(f, 1);
      lcd.print("-");
    }
    lcd.setCursor(15, 1);
    lcd.write((byte)4); //imprime a pastilha
    if (g % 2 == 0)
    {
      lcd.setCursor(i, 0);
      lcd.write((byte)0);
      lcd.setCursor(g, 1);
      lcd.write((byte)3);// imprimindo o caracter especial 1
    }
    else
    {
      lcd.setCursor(i, 0);
      lcd.write((byte)1);
      lcd.setCursor(g, 1);
      lcd.write((byte)pacman);// imprimindo o caracter especial 1
    }
    if (i % 2 == 0)//testa se o valor da variável é par, 
      g++;
    //e--;
    delay(tempo);
    lcd.clear();
  }
  e = 0;
  for ( i = 0; i < 15; i++)
  {
   
    for (f = g; f < 16; f++)
    {
      lcd.setCursor(f, 1);
      lcd.print("-");
    }
    lcd.setCursor(15, 1);
    lcd.write((byte)4); //imprime a pastilha
    if (g % 2 == 0)
    {
      lcd.setCursor(i, 1);
      lcd.write((byte)0);
      lcd.setCursor(g, 1);
      lcd.write((byte)3);// imprimindo o caracter especial 1
    }
    else
    {
      lcd.setCursor(i, 1);
      lcd.write((byte)1);
      lcd.setCursor(g, 1);
      lcd.write((byte)pacman);// imprimindo o caracter especial 1

    }
     if (i % 2 == 0)
      g++;
    //e++;
    delay(tempo);
    lcd.clear();
  }
/////////retorno//////////
  e = 14;
  g=16;
  for ( i = 0; i < 16; i++)
  {
    if (i % 2 == 0)
      g--;
    if (g % 2 == 0)
    {
      lcd.setCursor(e, 1);
      lcd.write((byte)0);
      lcd.setCursor(g, 1);
      lcd.write((byte)3);// imprimindo o caracter especial 1
    }
    else
    {
      lcd.setCursor(e, 1);
      lcd.write((byte)1);
      lcd.setCursor(g, 1);
      lcd.write((byte)5);// imprimindo o caracter especial 1

    }
    e--;
    delay(tempo);
    lcd.clear();
  }
///////////////////////////////
  for ( i = 0; i < 16; i++)
  {
    if (i % 2 == 0)
      g--;

    if (g % 2 == 0)
    {
      lcd.setCursor(i, 0);
      lcd.write((byte)0);
      lcd.setCursor(g, 1);
      lcd.write((byte)3);// imprimindo o caracter especial 1
    }
    else
    {
      lcd.setCursor(i, 0);
      lcd.write((byte)1);
      lcd.setCursor(g, 1);
      lcd.write((byte)5);// imprimindo o caracter especial 1
    }
    delay(tempo);
    lcd.clear();
  }

}