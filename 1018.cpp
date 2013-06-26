#include<iostream>
#include<iomanip>
using namespace std;
#define MAX 65535
class device
{
public:
	int bandwidth;
	int price;
	int device_id;
};
//device_id : 0 -> n-1
//
int get_solution( int num_devices, int *manu_per_device, device *devices_info,int device_id, int band, int price)
{
	int total_price=price;
	for( int i=0; i<num_devices; i++)
	{
		if( i == device_id)
			continue;
		int num_manu = manu_per_device[i];
		int min_price = MAX;
		for( int k=0; k<num_manu; k++)
		{
			int index = i * 100 + k;
			if( (devices_info[index].bandwidth >= band) && (devices_info[index].price < min_price) ) 
			{
				min_price = devices_info[index].price;
			}
		}

		if ( min_price == MAX )// has no solutions!
		{	
			return 0;
		}
		total_price += min_price;
	}
	return total_price;
}

int main()
{
	int num_case;
	cin >> num_case;
	for( int i=0; i< num_case; i++)
	{
		int num_devices;
		cin >> num_devices;
		int *manu_per_device;
		manu_per_device = new int[num_devices];

		int *max_band = new int[num_devices +1];//
		max_band[0] = -1;

		device *devices_info = new device[num_devices * 100 +1];

		for( int j=0; j< num_devices; j++)
		{
			int num_m;//manufactors 
			cin >> num_m;
			manu_per_device[j] = num_m;

			for( int k=0; k<num_m; k++)
			{
				int bandwidth, price;
				cin >> bandwidth >> price;
				if( bandwidth > max_band[j+1] )
					max_band[j+1] = bandwidth;

				int index = j * 100 + k;
				devices_info[index].bandwidth = bandwidth;	
				devices_info[index].price = price;
				devices_info[index].device_id = j;
			}
		}
		float final_bp = 0.0;
		//begin to computing !
		for( int j=0;j< num_devices;j++)
		{
			int num_m = manu_per_device[j];
			for( int k=0; k<num_m; k++)
			{
				//get a device and set it the final bandwith
				//
				int index = j * 100 + k;
				int band = devices_info[index].bandwidth;
				int price = devices_info[index].price;
				float bp;
				//now get the other n-1 devices(should bandwith >= band ), and the total price
				int total_price = get_solution( num_devices, manu_per_device, devices_info, j, band, price);
				if( total_price )
				{
					 bp = band*1.0/total_price;
					 if ( bp > final_bp )
						 final_bp = bp;
				}
			}
		}
		cout << fixed << setprecision(3) << final_bp << endl;
		delete manu_per_device;
		delete max_band;
		delete devices_info;
	}
	return 0;
}
