#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include <stdio.h>
#include <string>
#include <ximaging_formats.h>

using namespace std;

int main( int argc, char* argv[]  )
{
    int rc = 0;

    // _CrtSetBreakAlloc(1);

    {
        ximage* image = nullptr;
        string  outFileName;

        if ( argc != 2 )
        {
            printf( "Usage: jpg2png <file_name> \n\n" );
            rc = 1;
        }

        if ( rc == 0 )
        {
            printf( "Input: %s \n", argv[1] );

            // decode from JPEG
            if ( XDecodeJpeg( argv[1], &image ) != SuccessCode )
            {
                printf( "Error: failed decodeing input image \n\n" );
                rc = 2;
            }
        }

        if ( rc == 0 )
        {
            char* dotPtr = strrchr( argv[1], '.' );

            if ( dotPtr )
            {
                outFileName = string( argv[1], dotPtr - argv[1] );
            }
            else
            {
                outFileName = argv[1];
            }

            outFileName += ".png";
        }

        if ( rc == 0 )
        {
            printf( "Output: %s \n", outFileName.c_str( ) );

            // encode into PNG
            if ( XEncodePng( outFileName.c_str( ), image ) != SuccessCode )
            {
                printf( "Error: failed encoding output image \n\n" );
                rc = 3;
            }
        }

        XImageFree( &image );
    }

    #ifdef _MSC_VER
    _CrtDumpMemoryLeaks( );
    #endif

    return 0;
}
