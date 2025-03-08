#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

int Arr_Size =50, Int_Bytes =4; //The size of the array & the byte of int on memory
int Sensor_Data[50];
int Sensor_Data_i = 0;

int MAX_ITTIRATIONS =4;
 
void sensor_data()						// Generating sensor data 
{
        int sensor =0 ;
        sensor =rand()%(5+1);           // Generating number of bytes
        int Byte_array[sensor];
       
        for(int byte_i=0;byte_i<sensor; byte_i++)   // Generating bytes 
        {
          Byte_array[byte_i]  = rand()%(255+1); 
          
        }    
        if((Sensor_Data_i+sensor) <50)                // Checking the array size
        {
            for(int byte_arr_i =0;byte_arr_i<sensor;byte_arr_i++)
            {
                Sensor_Data[Sensor_Data_i] = Byte_array[byte_arr_i]; // adding bytes to the array
                Sensor_Data_i++;
            }
        }            
        else
        {
            int j;
            for(j=0;j<((sizeof(Sensor_Data)/Int_Bytes)-sensor);j++)     // updating the latest data & deleting older data
            {
                Sensor_Data[j] = Sensor_Data[j+sensor];
            }
            Sensor_Data_i = j;
            for(int byte_arr_i =0; byte_arr_i<sensor; byte_arr_i++)
            {
                Sensor_Data[Sensor_Data_i] = Byte_array[byte_arr_i];
                Sensor_Data_i++;
            }
        }
}
void print_data()															// evaluating and printing the sensor data array 
{
    if(Sensor_Data_i >= 50)
        {
            printf("\nSensor data in Hex :");
            for(int i=0;i<(sizeof(Sensor_Data)/Int_Bytes);i++)
            {
                if(i == (sizeof(Sensor_Data)/Int_Bytes)-1)
                {
                    printf("0x%X \n" ,Sensor_Data[i]);
                }
                else
                {
                    printf("0x%X, " ,Sensor_Data[i]);
                }
            }
            Sensor_Data_i = 0;
        }
        else
        {
            printf("\nArray is not full");
            
        }
}

int main() {
	int cntr=0;
	int ittirations =0;
	while(ittirations<MAX_ITTIRATIONS)
	{
    	while(cntr<11)
    	{
    	    if(cntr<=9)
    	    {
    	        sleep(1);
    	        sensor_data();   
    	        cntr++;
    	    }
    	    else
    	    {
    	        print_data();
    	        cntr++;
    	    }
    	}
    	ittirations++;
    	cntr =0;
	}

}

