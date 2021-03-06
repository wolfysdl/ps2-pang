
#include <string.h>
#include <stdio.h>

#include "GfxEngine.h"


void showNumber(char *string,unsigned int x,unsigned int y)

{

	unsigned char i,temp;
	int positionxduzero=148;
	int positionyduzero=226;
	
	temp=strlen(string);
	for(i=0;i<temp;i++)
		{       
          if ( ((*string-48)*13) == 0 )
          {
                    blitImageToScreen(1,((*string-48)*14)+positionxduzero,positionyduzero,13,13,x+(i*13),y,13,13,320,240);
          }
          else
          {
                    blitImageToScreen(1,((*string-48)*14)+positionxduzero+1,positionyduzero,13,13,x+(i*13),y,13,13,320,240);             
          }
          
          string++;
		}
}

void initObjets()
{
	int i;
	for (i=0;i<MAX_OBJETS;i++)
	{
		obj[i].utilise = 0;
	}
}

void createObjet(int type,int x,int y,int value)
{
	int i;
	i=0;
	while ((obj[i].utilise==1) && (i<MAX_OBJETS) )
	{
		i++;
	}
	
	obj[i].type=type;
	obj[i].posx=x;
	obj[i].posy=y;
	obj[i].value=value;
	obj[i].utilise=1;
	
	if (type==OBJ_MUL)
	{
		obj[i].cpt=20;
	} else if (type==OBJ_1UP)
	{
		obj[i].cpt=100;
	} else if ((type==OBJ_EXPL_BIG)||(type==OBJ_EXPL_NORMAL)||(type==OBJ_EXPL_SMALL)||(type==OBJ_EXPL_MICRO)) 
	{
		obj[i].cpt=20;
	}
}

void showObjet(int i)
{
	if (obj[i].utilise==1)
	{
		if (obj[i].type==OBJ_MUL)
		{
			if (obj[i].cpt>0)
			{
//   			G	pTextOut(NULL, &gpDraw[nflip], obj[i].posx, obj[i].posy, "x", INVISIBLE_COLOR);
				char chaine[2];
				sprintf(chaine, "%d", obj[i].value);	
				blitImageToScreen(1,247,90,7,9,obj[i].posx,obj[i].posy,7,9,320,240);	
				
                		showNumber(chaine,obj[i].posx+8, obj[i].posy);
//				GpTextOut(NULL, &gpDraw[nflip], obj[i].posx+8, obj[i].posy, chaine, INVISIBLE_COLOR);

                		obj[i].posy--;
				obj[i].cpt--;
			}
			else
			{
				obj[i].utilise=0;
			}
		} else 
		if (obj[i].type==OBJ_1UP)
		{
			if (obj[i].cpt>0)
			{
//				GpTextOut(NULL, &gpDraw[nflip], obj[i].posx, obj[i].posy, "1UP", INVISIBLE_COLOR);
               			blitImageToScreen(1,240,12,21,13,obj[i].posx,obj[i].posy,21,13,320,240);	
				obj[i].cpt--;
				obj[i].posy--;
			}
			else
			{
				obj[i].utilise=0;
			}
		}		
	}
}
