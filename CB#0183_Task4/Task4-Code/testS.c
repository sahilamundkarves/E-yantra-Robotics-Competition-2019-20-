/*
**
Team Id: 0183
* Author List: Sahil Amundkar, Abhijeet Kale, Samruddha Kalke, Raj Talashilkar
* Filename: main.c
* Theme: Construct-O-Bot
* Functions: natural behaviour(), back behaviour()
**
*/




#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "functions.c"
int x=20,y= 20,a=80,b=300;
int n=1,k=1,z=1,p=90;
unsigned char prox_value1=0,prox_value2=0;
unsigned int prox=500,prox2=0;

int main(void)

{
	
	init_devices();
	binit_devices();
	lcd_set_4bit();
	sinit_devices();
	
	lcd_cursor(1,3);
	lcd_string("DIDI");
	

	
	while(n==1)
	{
		unsigned int left_sensor=ADC_Conversion(1);			//value from left sensor
		unsigned int right_sensor=ADC_Conversion(3);		//value from right sensor
		unsigned int centre_sensor=ADC_Conversion(2);		//value from centre sensor
		
		natural_behav();
		
		if(left_sensor > x && centre_sensor > y && right_sensor > x)		//node condition
		{
			velocity(150,150);
			forward();
			_delay_ms(350);
			
			velocity(150,150);
			right();
			_delay_ms(850);
			n++;
		}
	}
	
	while(n==2)
	{
		unsigned int left_sensor=ADC_Conversion(1);
		unsigned int right_sensor=ADC_Conversion(3);
		unsigned int centre_sensor=ADC_Conversion(2);
		
		natural_behav();
		
		if((left_sensor > x && centre_sensor > y && right_sensor > x) || (left_sensor < x && centre_sensor > y && right_sensor > x))
		{
			velocity(150,150);
			forward();
			_delay_ms(350);
			
			velocity(150,150);
			right();
			_delay_ms(850);
			
			n++;
		}
		
	}
	
		while(n==3)
		{
			unsigned int left_sensor=ADC_Conversion(1);
			unsigned int right_sensor=ADC_Conversion(3);
			unsigned int centre_sensor=ADC_Conversion(2);
			
			natural_behav();
			
			if(left_sensor > x && centre_sensor > y && right_sensor > x)
			{
				velocity(150,150);
				forward();
				_delay_ms(350);
				right();
				_delay_ms(800);
				n++;
				
			}
			
		}
		while(n==4)		//for pick up of construction material
		{
			unsigned int left_sensor=ADC_Conversion(1);
			unsigned int right_sensor=ADC_Conversion(3);
			unsigned int centre_sensor=ADC_Conversion(2);
			if(left_sensor<x && centre_sensor <y && right_sensor>x)
			{
				velocity(90,90);
				right();
			}
			if(left_sensor>x && centre_sensor <y && right_sensor<x)
			{	
				velocity(90,90);
				left();
			}
			if(left_sensor<x && centre_sensor>y && right_sensor<x)
			{
				prox_value1 = ADC_Conversion(9);
				prox = Sharp_GP2D12_estimation(prox_value1);		//taking values from proximity sensor1 placed at the front of the bot
				lcd_print(2,14,prox,3);
				
				if(prox > 100)
				{	velocity(90,90);
					forward();
				}
				
				else if(prox > 90 && prox < 99)
				{
					stop();
					_delay_ms(1000);
					
					down_pick_up();
					_delay_ms(1000);
					
					stop();
					_delay_ms(1000);
					
					back();
					_delay_ms(250);
					n++;
				}
				else if(prox< 89)
				{	
					velocity(90,90);
					back();
				}
				
			}
			
			
		}



	while(n==5)
	{
		unsigned int left_sensor=ADC_Conversion(1);
		unsigned int right_sensor=ADC_Conversion(3);
		unsigned int centre_sensor=ADC_Conversion(2);
		
		back_behav();
		
		if(left_sensor> x && centre_sensor> y && right_sensor> x)
		{
			velocity(150,150);
			forward();
			_delay_ms(500);
			
			velocity(150,150);
			left();
			_delay_ms(300);
			
			n++;
		}
	}

	while(n==6)
	{
		unsigned int left_sensor=ADC_Conversion(1);
		unsigned int right_sensor=ADC_Conversion(3);
		unsigned int centre_sensor=ADC_Conversion(2);
		
		natural_behav();
		
		if(left_sensor> x && centre_sensor> y && right_sensor> x)
		{
			velocity(150,150);
			forward();
			_delay_ms(350);
			
			n++;
		}
	}
	
	while(n==7)
	{
		unsigned int left_sensor=ADC_Conversion(1);
		unsigned int right_sensor=ADC_Conversion(3);
		unsigned int centre_sensor=ADC_Conversion(2);
		
		natural_behav();
		
		if(left_sensor > x && centre_sensor> y && right_sensor> x)
		{
			velocity(150,150);
			forward();
			_delay_ms(350);
			
			n++;
		}
	}
	
	while(n==8)
	{
		unsigned int left_sensor=ADC_Conversion(1);
		unsigned int right_sensor=ADC_Conversion(3);
		unsigned int centre_sensor=ADC_Conversion(2);
		
		natural_behav();
		
		if(left_sensor> x && centre_sensor> y && right_sensor> x)
		{
			velocity(150,150);
			forward();
			_delay_ms(350);
			
			velocity(150,150);
			right();
			_delay_ms(850);
			
			n++;
		}
	}
	
	while(n==9)
	{
		unsigned int left_sensor=ADC_Conversion(1);
		unsigned int right_sensor=ADC_Conversion(3);
		unsigned int centre_sensor=ADC_Conversion(2);
		
		natural_behav();
		
		if(left_sensor> x && centre_sensor> y && right_sensor> x)
		{
			velocity(150,150);
			forward();
			_delay_ms(250);

			n++;
		}
	}
	
	while(n==10)		//for placement of contruction material 
	{
		unsigned int left_sensor=ADC_Conversion(1);
		unsigned int right_sensor=ADC_Conversion(3);
		unsigned int centre_sensor=ADC_Conversion(2);
		prox_value1 = ADC_Conversion(9);
		prox = Sharp_GP2D12_estimation(prox_value1);
		lcd_print(2,14,prox,3);
		
		
		if(prox >81 && prox <83)
		{
			stop();
			_delay_ms(1000);
			
			place();
			_delay_ms(1000);
			
			back();
			_delay_ms(250);
			n++;
		}
		else if (prox >84)
		{	
			velocity(80,80);
			forward();
		}
		
			
	}
	
	while(n==11)
	{
		unsigned int left_sensor=ADC_Conversion(1);
		unsigned int right_sensor=ADC_Conversion(3);
		unsigned int centre_sensor=ADC_Conversion(2);
		
		back_behav();
		
		if(left_sensor > x && centre_sensor > y && right_sensor >x)
		{
			left();
			_delay_ms(600);
			n++;
		}
	}
	/******************************H4 STARTS**************************/
	
	while(n==12)
		{
		
			unsigned int left_sensor=ADC_Conversion(1);
			unsigned int right_sensor=ADC_Conversion(3);
			unsigned int centre_sensor=ADC_Conversion(2);
			
			natural_behav();
			
			if(left_sensor> x && centre_sensor> y && right_sensor> x)
			{	
				velocity(150,150);
				forward();
				_delay_ms(350);
			
				velocity(150,150);
				left();
				_delay_ms(850);
				
				n++;
			}
	
		
		}
			
		while(n==13)
		{
			unsigned int left_sensor=ADC_Conversion(1);
			unsigned int right_sensor=ADC_Conversion(3);
			unsigned int centre_sensor=ADC_Conversion(2);
			
			natural_behav();

			if(left_sensor> x && centre_sensor> y && right_sensor> x)
			{	
				velocity(150,150);
				forward();
				_delay_ms(350);
				right();
				_delay_ms(800);
				n++;
			}
			
		}
		

		while(n==14)
		{
			unsigned int left_sensor=ADC_Conversion(1);
			unsigned int right_sensor=ADC_Conversion(3);
			unsigned int centre_sensor=ADC_Conversion(2);
			if(left_sensor<x && centre_sensor <y && right_sensor>x)
			{
				right();
			}
			if(left_sensor>x && centre_sensor <y && right_sensor<x)
			{
				left();
			}
			if(left_sensor<x && centre_sensor>y && right_sensor<x)
			{
				prox_value1 = ADC_Conversion(9);
				prox = Sharp_GP2D12_estimation(prox_value1);
				lcd_print(2,14,prox,3);
				
				if(prox > 100)
				{	velocity(100,100);
					forward();
				}
				
				else if(prox > 90 && prox < 99)
				{
					stop();
					_delay_ms(1000);
					
					down_pick_up();
					_delay_ms(1000);
					
					stop();
					_delay_ms(1000);
					
					back();
					_delay_ms(250);
					n++;
				}
				else if(prox< 89)
				{
					back();
				}
				
			}			
		}
		
		while(n==15)
		{
			unsigned int left_sensor=ADC_Conversion(1);
			unsigned int right_sensor=ADC_Conversion(3);
			unsigned int centre_sensor=ADC_Conversion(2);
			
			back_behav();
			
			if(left_sensor> x && centre_sensor> y && right_sensor> x)
			{
				velocity(150,150);
				forward();
				_delay_ms(500);
				
				velocity(150,150);
				left();
				_delay_ms(300);
				
				n++;
			}
		}
		
		while(n==16)
		{
			unsigned int left_sensor=ADC_Conversion(1);
			unsigned int right_sensor=ADC_Conversion(3);
			unsigned int centre_sensor=ADC_Conversion(2);
			
			natural_behav();
			
			if(left_sensor> x && centre_sensor> y && right_sensor> x)
			{
				velocity(150,150);
				forward();
				_delay_ms(350);
				
				velocity(150,150);
				left();
				_delay_ms(800);
				
				n++;
			}
		}
		
		
		while(n==17)
		{
			unsigned int left_sensor=ADC_Conversion(1);
			 unsigned int right_sensor=ADC_Conversion(3);
			unsigned int centre_sensor=ADC_Conversion(2);
			
			if(centre_sensor>y && left_sensor <x && right_sensor <x)
			{
				velocity(150,150);
				forward();
			}
			if(left_sensor<x && centre_sensor <y && right_sensor>x)
			{
				velocity(130,130);
				right();
			}
			if(left_sensor>x && centre_sensor <y && right_sensor<x)
			{
				velocity(130,130);
				left();
			}
			if(left_sensor<x && centre_sensor<y && right_sensor<x)
			{
				prox_value2 = ADC_Conversion(10);
				prox2 = Sharp_GP2D12_estimation(prox_value2);
				lcd_print(1,14,prox2,3);
				
				if(prox2 > 600 )
				{
					velocity(100,100);
					forward();
				}				
				if(prox2 > 124 && prox < 600)
				{
					velocity(125,125);
					soft_right();
				}
				else if(prox2 < 121 )
				{
					velocity(125,125);
					soft_left();
				}
				else if(prox2 > 119  && prox2 < 126 )
				{
					velocity(135,135);
					forward();
				}
				
			}
			if (left_sensor>x && centre_sensor >y && right_sensor>x)
			{
				forward();
				_delay_ms(200);
				n++;
			}
			
		}
		
		while(n == 18)
		{
			unsigned int left_sensor=ADC_Conversion(1);
			unsigned int right_sensor=ADC_Conversion(3);
			unsigned int centre_sensor=ADC_Conversion(2);
			prox_value1 = ADC_Conversion(9);
			prox = Sharp_GP2D12_estimation(prox_value1);
			lcd_print(2,14,prox,3);
		
		
			if(prox >81 && prox <83)
			{
				place();
				stop();
				_delay_ms(10000);
				
				n++;
			}
			else if (prox >84)
			{	
				velocity(80,80);
				forward();
			}
		
		}
		
		while(n == 19)
		{
				buzzer_on();
				_delay_ms(5000);
				n++;
		}
	}




		
//this function is used for aligning the bot on the black line while moving forward
void natural_behav(void)
{
	unsigned int left_sensor=ADC_Conversion(1);
	unsigned int right_sensor=ADC_Conversion(3);
	unsigned int centre_sensor=ADC_Conversion(2);
	if(left_sensor<x && centre_sensor>y && right_sensor<x)
	{
		velocity(150,150);
		forward();
	}
	if(left_sensor<x && centre_sensor<y && right_sensor>x)
	{
		velocity(100,100);
		right();
	}
	if(left_sensor>x && centre_sensor<y && right_sensor<x)
	{
		velocity(100,100);
		left();
	}
}

//this function is used for aligning the bot on the black line while moving backward
void back_behav(void)
{
	unsigned int left_sensor=ADC_Conversion(1);
	unsigned int right_sensor=ADC_Conversion(3);
	unsigned int centre_sensor=ADC_Conversion(2);
	
	if(left_sensor<x && centre_sensor>y && right_sensor<x)
	{
		velocity(150,150);
		back();
	}
	if(left_sensor<x && centre_sensor<y && right_sensor>x)
	{
		velocity(100,100);
		right();
	}
	if(left_sensor>x && centre_sensor<y && right_sensor<x)
	{
		velocity(100,100);
		left();
	}

}

