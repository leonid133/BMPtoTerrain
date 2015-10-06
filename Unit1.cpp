//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "matrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
   : TForm(Owner)
{
   image Terrain;
   ifstream FileIn("Terrain.bmp", ios::binary);
   ofstream FileOut("Terrain.raw");
   if(FileIn)
   {
      Terrain.LoadFromFile(FileIn);
      FileIn.close();
  /*    int m, n;
      m = Terrain.Y.m;
      n = Terrain.Y.n;
      int temp = 10;
      Terrain.Convolution(FilterGauss(0.7, 3, 5));  */
      //Terrain.Eqalization();
     /*
      for(int i=0; i<m; i++)
      {
         for(int j=0; j<n; j++)
         {
            if(Terrain.R.ar[i*n + j]>147 && Terrain.R.ar[i*n + j]<185 && Terrain.G.ar[i*n + j]>248 && Terrain.G.ar[i*n + j]<255 && Terrain.B.ar[i*n + j]>130 && Terrain.B.ar[i*n + j]<164)
               temp = 30;
            if(Terrain.R.ar[i*n + j]>199 && Terrain.R.ar[i*n + j]<228 && Terrain.G.ar[i*n + j]>250 && Terrain.G.ar[i*n + j]<255 && Terrain.B.ar[i*n + j]>171 && Terrain.B.ar[i*n + j]<201)
               temp = 60;
            if(Terrain.R.ar[i*n + j]>247 && Terrain.R.ar[i*n + j]<255 && Terrain.G.ar[i*n + j]>253 && Terrain.G.ar[i*n + j]<255 && Terrain.B.ar[i*n + j]>198 && Terrain.B.ar[i*n + j]<211)
               temp = 120;
            if(Terrain.R.ar[i*n + j]>250 && Terrain.R.ar[i*n + j]<255 && Terrain.G.ar[i*n + j]>210 && Terrain.G.ar[i*n + j]<230 && Terrain.B.ar[i*n + j]>179 && Terrain.B.ar[i*n + j]<185)
               temp = 250;
            Terrain.Y.ar[i*n + j] = temp;
            temp = temp - 3;
         }
         temp = temp - 3;
      }
      */
      Terrain.DrawY();
      Terrain.SaveFromFile(FileOut);
      FileOut.close();
   }
   else
   {
      FileIn.close();
      FileOut.close();
   }

}
//---------------------------------------------------------------------------
