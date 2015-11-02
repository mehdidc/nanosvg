#define NANOSVG_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#include "nanosvg.h"


int main(int argc, char **argv){
	NSVGimage* image;
        int dpi;
        if(argc <= 1){
            printf("Usage : filename.svg dpi=96\n");
            return 0;
        }
        if(argc <= 2){
            dpi = 96;
        }
        else{
            dpi = atoi(argv[2]);
        }
	image = nsvgParseFromFile(argv[1], "px", dpi );

	printf("size: %f x %f\n", image->width, image->height);
	// Use...
        NSVGshape *shape;
        NSVGpath *path;
        int i;
	for (shape = image->shapes; shape != NULL; shape = shape->next) {
		for (path = shape->paths; path != NULL; path = path->next) {
			for (i = 0; i < path->npts-1; i += 3) {
				float* p = &path->pts[i*2];
                                printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f\n", p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
				//drawCubicBez(p[0],p[1], p[2],p[3], p[4],p[5], p[6],p[7]);

			}
		}
	}
	// Delete
	nsvgDelete(image);
}
