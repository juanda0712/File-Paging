/***************************************************************************//**
 * ITCR
 *
 * Juan Daniel Rodriguez Montero
 * Algoritmos y estructuras de datos 2
 * 2020426163
 *
 ******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std;


/*!
 ... this class stores an array of 256 integers, the integer "bit" for the replacement algorithm and the page number ...
*/
class Page{
private:
    int pageNumber = 0;
    int arrayNumbers[256];
    int bit = 0;

public:
    // Setters
    void setpageNumber(int pageNumber) {
        this->pageNumber = pageNumber;
    }
    void setarrayNumbers(int arrayPosition, int value) {
        this->arrayNumbers[arrayPosition] = value;
    }
    void setbit(int bit) {
        this->bit = bit;
    }

    // Getters
    int getpageNumber() {
        return pageNumber;
    }
    int* getarrayNumbers() {
        return arrayNumbers;
    }
    int getbit() {
        return bit;
    }
};


/*!
 ... this function receives the pointer to an array and orders it ...
*/
void insertionSort(int *array, int size)
{
    int key, j;
    for(int i = 1; i<size; i++) {
        key = array[i];//take value
        j = i;
        while(j > 0 && array[j-1]>key) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = key;   //insert in right place
    }
}

/*!
 ... this function receives two arrays for the ordering algorithm to order them both ...
*/
void twoPagesOrdering(int *array1, int *array2 )
{
    int combineArray[512];

    for (int i = 0; i < 256 ; ++i) {
        combineArray[i] = array1[i];
        combineArray[i+256] = array2[i];
    }

    insertionSort(combineArray,512);
    //combineArray ahora esta ordenado

    for (int n = 0; n < 256; ++n) {
        array1[n] = combineArray[n];
        array2[n] = combineArray[n+256];
    }
}

/*!
 ... the replacement algorithm returns an integer that is the position in the page array in which there is a page with bit 0 (unoccupied) ...
*/
int clockReplacementAlgorithm(Page* ptrArray)
{
    for (int i = 0; i < 6; ++i)
    {
        if (ptrArray[i].getbit() == 0)
        {
            return i;
        }
    }
}

void read()
{
    ifstream lector;
    string texto;
}
void overidePage(Page page)
{

}

void extractVirtualPage(int pageNumber, int position)
{
    int start = ((pageNumber-1)*256)+1;
    int end = pageNumber * 256;
}


/*!
 ... esta clase sobrecarga el operador [] para poder determinar la pagina que debe retornar o reemplazar  ...
     A class to represent an Page array
*/

class PagedArray {
private:
    Page* ptr;
    int size;

public:
    // constructor for array class
    PagedArray(Page* p = NULL, int size = 0)
    {
        this->size = size;
        ptr = NULL;
        if (size != 0) {
            ptr = new Page[size];
            for (int i = 0; i < size; i++)
                ptr[i] = p[i];
        }
    }
    // Overloading [] operator to access elements in array style
    // Implementation of [] operator.  This function must return a
    // reference as array element can be put on left side
    Page& operator[](int index)
    {
        for (int i = 0; i < 6; ++i)
        {
            if (this->ptr[i].getpageNumber() == index)
            {
                return this->ptr[i];
            }
        }
        int position = clockReplacementAlgorithm(ptr);
        if (this->ptr[position].getpageNumber() != 0)
        {
            overidePage(this->ptr[position]);
            extractVirtualPage(index,position);
        }else{
            extractVirtualPage(index,position);
        }
    }
};


/*!
 ... this function captures the name of the file to sort and the name of the resulting file ...
*/
void captureConsoleFileNames(string* file, string* finalFile, string comando)
{
    char arr[comando.length() + 1];
    char *token;
    int count = 0;

    for (int x = 0; x < sizeof(arr); x++) {
        arr[x] = comando[x];
    }

    token = strtok(arr," ");

    while (token != NULL){
        count++;
        token = strtok(NULL," ");

        if (count == 2 ){
            *file += token;
        }
        if (count == 5){
            *finalFile += token;
        }
    }
}



int main()
{
    Page arrayForPhysicalPages[6];
    string comando;
    string archivo= "";
    string archivo_resultado = "";
    int totalPagesOfTheFile;

    cout << "Ingrese el comando: " << endl;
    getline(cin, comando);
    captureConsoleFileNames(&archivo, &archivo_resultado, comando);

    cout << archivo << endl;
    cout << archivo_resultado << endl;



    for (int i = 1; i <= totalPagesOfTheFile; ++i) {

        for (int j = 2; j <= totalPagesOfTheFile; ++j) {

        }
        //cuando sale del segundo ciclo la pagina del primer
        //ciclo estara ordenada y lista para enviarla al archivo final
    }


    return 0;
}