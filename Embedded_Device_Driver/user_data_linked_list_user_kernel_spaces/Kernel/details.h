#define DISP_AB 	_IOR('z', 123, unsigned int *)
#define DISP_CD	_IOR('z', 124, unsigned int *)
#define DISP_EF 	_IOR('z', 125, unsigned int *)
#define DISP_GH	_IOR('z', 126, unsigned int *)
#define DISP_ERR 	_IOR('z', 127, unsigned int *)
#define CLEANUP	_IOR('z', 128, unsigned int *)

#define READ_AB 	_IOR('z', 129, unsigned int *)
#define READ_CD	_IOR('z', 130, unsigned int *)
#define READ_EF 	_IOR('z', 131, unsigned int *)
#define READ_GH	_IOR('z', 132, unsigned int *)
#define READ_ERR 	_IOR('z', 133, unsigned int *)


/*
enum{	
	DISP_AB	,	
	DISP_CD	,	
	DISP_EF	,	
	DISP_GH	,	
	DISP_ERR	,	
	LENGTH
}Link_lengths;

*/

struct details
{
	char name[10];
	char address[50];
	char id[10];
};
