#include <string>
#include <iostream>
#include <vector>
using namespace::std;

//Constarint is that all resources need to have that signature for their constructor
//And a seperate header as well

//-----------------------Headers-------------------------
struct MeshHeader
{
	char* path;
	int id;
	int vertices;
};

struct TextureHeader
{
	char* path;
	int id;
};
//-------------------------XXX-------------------------------

//---------------------Header Holder-------------------------
template<typename T>
class Data
{
	
public :
	T data;
	Data()	{}
	template<typename T>
	T& GetData()	{ return data;	}
	T operator= (T& other)	{ data = other;	}
};
//-------------------------XXX-------------------------------

//-----------------------Base Loader-------------------------
class ResourceLoader
{
public:
	
	template<typename T, typename DataType>
	T& Load(Data<DataType> data_)
	{	
		T* ptr = new T(data_);
		ptr->Load();
		return *ptr;
	}
};
//-------------------------XXX-------------------------------

//-------------------------Resources-------------------------
class Texture 
{
	
public:
	template<typename T>
	Texture(Data<T>) { }

	void Load()
	{
		printf("Loading Texture \n");
	}
};


class Mesh
{
	public:

	template<typename T>
	Mesh(Data<T>)	{}

	void Load()
	{
		printf("Loading Mesh \n");
	}
};
//-------------------------XXX-------------------------------


int main()
{
	Data<TextureHeader> texH;	
	Data<MeshHeader> meshH;

	ResourceLoader* loader = new ResourceLoader();
	loader->Load<Texture>(texH);
	loader->Load<Mesh>(meshH);

	system("pause");
}
