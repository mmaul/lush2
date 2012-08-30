/* WARNING: Automatically generated code.
 * This code has been generated by the DH compiler.
 */
#ifdef HAVE_CONFIG_H
# include "lushconf.h"
#endif

/*
 * LUSH HEADERS
 */
#include "header.h"
#include "dh.h"
#include "idxmac.h"
#include "idxops.h"
#include "check_func.h"
#undef uchar

/*
 * DECLARATIONS
 */
extern_c gptr  C_popen ( char* , char*  );
extern_c index_t *  C_pnm_fread_rgb ( FILE *  );
extern_c bool  C_pclose ( FILE *  );
extern_c index_t *  C_pnm_fread_rgba ( FILE *  );
extern_c bool  C_pnm_fread_into_ubim ( FILE * , index_t *  );
extern_c index_t *  C_pnm_fread_ubim ( FILE *  );
extern_c bool  C_ppm_fwrite_rgb ( FILE * , index_t *  );
extern_c bool  C_pgm_fwrite_ubim ( FILE * , index_t *  );


/* ---------------------------------------- */


/*
 * FUNCTION image-read-rgb
 */
extern_c index_t * C_image_read_rgb(char* L1_s)
{
TRACE_PUSH("C_image_read_rgb"); MM_ENTER;
{
index_t * L_Tmp0;
{
FILE * L2_1_f;
index_t * L_Tmp2_prog1ret;
char *L2_0_str;
{
char tempstr[1100]; int templen;
sprintf(tempstr,"%s -compress lossless -depth 8 %s PPM:-","/usr/bin/convert",(char *)(L1_s));
tempstr[sizeof(tempstr)-1] = 0;
templen = strlen(tempstr);
if (templen >= sizeof(tempstr)-1)
lush_error("sprintf buffer full");
Mstr_alloc(L2_0_str, templen+1);
strcpy((char*)(L2_0_str),tempstr);
}
char *L2_1_str;
Mstr_alloc(L2_1_str, 1+1);
strcpy((char*)(L2_1_str),"r");
L2_1_f = (gptr ) C_popen(L2_0_str, L2_1_str);
 if (!(L2_1_f)) { 
lush_error("couldn't open convert pipe file");
 } 
L_Tmp2_prog1ret = (index_t * ) C_pnm_fread_rgb(L2_1_f);
MM_ANCHOR(L_Tmp2_prog1ret);
C_pclose(L2_1_f);
L_Tmp0 = L_Tmp2_prog1ret;
}
TRACE_POP("C_image_read_rgb");
MM_EXIT; return L_Tmp0;
}
}

/*
 * FUNCTION image-read-rgba
 */
extern_c index_t * C_image_read_rgba(char* L1_s)
{
TRACE_PUSH("C_image_read_rgba"); MM_ENTER;
{
index_t * L_Tmp0;
{
FILE * L2_1_f;
char *L2_0_str;
{
char tempstr[1100]; int templen;
sprintf(tempstr,"%s -compress lossless -depth 8 %s PPM:-","/usr/bin/convert",(char *)(L1_s));
tempstr[sizeof(tempstr)-1] = 0;
templen = strlen(tempstr);
if (templen >= sizeof(tempstr)-1)
lush_error("sprintf buffer full");
Mstr_alloc(L2_0_str, templen+1);
strcpy((char*)(L2_0_str),tempstr);
}
char *L2_1_str;
Mstr_alloc(L2_1_str, 1+1);
strcpy((char*)(L2_1_str),"r");
L2_1_f = (gptr ) C_popen(L2_0_str, L2_1_str);
 if (!(L2_1_f)) { 
lush_error("couldn't open convert pipe file");
 } 
{
index_t * L3_2_r;
Midx_declare(L3_3_4_select, 2);
gptr L_Tmp4;
Midx_init(L3_3_4_select, 2);
L3_2_r = (index_t * ) C_pnm_fread_rgba(L2_1_f);
C_pclose(L2_1_f);
char *L3_2_str;
{
char tempstr[1100]; int templen;
sprintf(tempstr,"%s -compress lossless -depth 8 -channel Matte %s PGM:-","/usr/bin/convert",(char *)(L1_s));
tempstr[sizeof(tempstr)-1] = 0;
templen = strlen(tempstr);
if (templen >= sizeof(tempstr)-1)
lush_error("sprintf buffer full");
Mstr_alloc(L3_2_str, templen+1);
strcpy((char*)(L3_2_str),tempstr);
}
char *L3_3_str;
Mstr_alloc(L3_3_str, 1+1);
strcpy((char*)(L3_3_str),"r");
L_Tmp4 = (gptr ) C_popen(L3_2_str, L3_3_str);
L2_1_f = (FILE * )(L_Tmp4);
 if (!(L2_1_f)) { 
lush_error("couldn't open alpha channel pipe file");
 } 
RTERR_GEN((((int)3) >= ((int)(L3_2_r)->dim[((int)2)])), "idx-select: subscript is too large");
Midx_select(L3_3_4_select,L3_2_r,((int)2),((int)3),unsigned char );
C_pnm_fread_into_ubim(L2_1_f, L3_3_4_select);
C_pclose(L2_1_f);
L_Tmp0 = L3_2_r;
}
}
TRACE_POP("C_image_read_rgba");
MM_EXIT; return L_Tmp0;
}
}

/*
 * FUNCTION image-read-ubim
 */
extern_c index_t * C_image_read_ubim(char* L1_s)
{
TRACE_PUSH("C_image_read_ubim"); MM_ENTER;
{
index_t * L_Tmp0;
{
FILE * L2_1_f;
index_t * L_Tmp2_prog1ret;
char *L2_0_str;
{
char tempstr[1100]; int templen;
sprintf(tempstr,"%s -compress lossless -depth 8 %s PPM:-","/usr/bin/convert",(char *)(L1_s));
tempstr[sizeof(tempstr)-1] = 0;
templen = strlen(tempstr);
if (templen >= sizeof(tempstr)-1)
lush_error("sprintf buffer full");
Mstr_alloc(L2_0_str, templen+1);
strcpy((char*)(L2_0_str),tempstr);
}
char *L2_1_str;
Mstr_alloc(L2_1_str, 1+1);
strcpy((char*)(L2_1_str),"r");
L2_1_f = (gptr ) C_popen(L2_0_str, L2_1_str);
 if (!(L2_1_f)) { 
lush_error("couldn't open convert pipe file");
 } 
L_Tmp2_prog1ret = (index_t * ) C_pnm_fread_ubim(L2_1_f);
MM_ANCHOR(L_Tmp2_prog1ret);
C_pclose(L2_1_f);
L_Tmp0 = L_Tmp2_prog1ret;
}
TRACE_POP("C_image_read_ubim");
MM_EXIT; return L_Tmp0;
}
}

/*
 * FUNCTION image-write-rgb
 */
extern_c bool C_image_write_rgb(char* L1_s,index_t * L1_im)
{
TRACE_PUSH("C_image_write_rgb"); MM_ENTER;
{
bool L_Tmp0;
{
FILE * L2_1_f;
bool L_Tmp2_prog1ret;
char *L2_0_str;
{
char tempstr[1100]; int templen;
sprintf(tempstr,"%s PPM:- %s","/usr/bin/convert",(char *)(L1_s));
tempstr[sizeof(tempstr)-1] = 0;
templen = strlen(tempstr);
if (templen >= sizeof(tempstr)-1)
lush_error("sprintf buffer full");
Mstr_alloc(L2_0_str, templen+1);
strcpy((char*)(L2_0_str),tempstr);
}
char *L2_1_str;
Mstr_alloc(L2_1_str, 1+1);
strcpy((char*)(L2_1_str),"w");
L2_1_f = (gptr ) C_popen(L2_0_str, L2_1_str);
 if (!(L2_1_f)) { 
lush_error("couldn't open convert pipe file");
 } 
L_Tmp2_prog1ret = (bool ) C_ppm_fwrite_rgb(L2_1_f, L1_im);
C_pclose(L2_1_f);
L_Tmp0 = L_Tmp2_prog1ret;
}
TRACE_POP("C_image_write_rgb");
MM_EXIT; return L_Tmp0;
}
}

/*
 * FUNCTION image-write-ubim
 */
extern_c bool C_image_write_ubim(char* L1_s,index_t * L1_im)
{
TRACE_PUSH("C_image_write_ubim"); MM_ENTER;
{
bool L_Tmp0;
{
FILE * L2_1_f;
bool L_Tmp2_prog1ret;
char *L2_0_str;
{
char tempstr[1100]; int templen;
sprintf(tempstr,"%s PGM:- %s","/usr/bin/convert",(char *)(L1_s));
tempstr[sizeof(tempstr)-1] = 0;
templen = strlen(tempstr);
if (templen >= sizeof(tempstr)-1)
lush_error("sprintf buffer full");
Mstr_alloc(L2_0_str, templen+1);
strcpy((char*)(L2_0_str),tempstr);
}
char *L2_1_str;
Mstr_alloc(L2_1_str, 1+1);
strcpy((char*)(L2_1_str),"w");
L2_1_f = (gptr ) C_popen(L2_0_str, L2_1_str);
 if (!(L2_1_f)) { 
lush_error("couldn't open convert pipe file");
 } 
L_Tmp2_prog1ret = (bool ) C_pgm_fwrite_ubim(L2_1_f, L1_im);
C_pclose(L2_1_f);
L_Tmp0 = L_Tmp2_prog1ret;
}
TRACE_POP("C_image_write_ubim");
MM_EXIT; return L_Tmp0;
}
}

/*
 * FUNCTION as-image
 */
extern_c index_t * C_as_image(index_t * L1_m)
{
TRACE_PUSH("C_as_image"); MM_ENTER;
{
index_t * L_Tmp0;
index_t *L2_2_array = new_empty_index(2);
storage_t *L2_2_srg = new_storage(ST_UCHAR);
{
Midx_declare0(L2_1_0_array);
Msrg_declare(L2_2_0_srg);
double L2_3_min;
Midx_declare0(L2_4_1_array);
Msrg_declare(L2_5_1_srg);
double L2_6_max;
index_t * L2_7_img;
Midx_declare(L4_8_3_new_idx, 1);
index_t * L2_9_mv;
storage_t * L2_10_isrg;
double L2_11_s;
index_t * L_Tmp12;
index_t * L_Tmp13;
(L2_1_0_array)->ndim = 0;
Msrg_init(L2_2_0_srg, ST_DOUBLE);
(L2_4_1_array)->ndim = 0;
Msrg_init(L2_5_1_srg, ST_DOUBLE);
Midx_init(L4_8_3_new_idx, 1);
(L2_1_0_array)->st = L2_2_0_srg;
Midx_init_dim0(L2_1_0_array);
check_main_m0out(L1_m,L2_1_0_array);
Midx_m2inf(L1_m,L2_1_0_array,double ,double );
L_Tmp12 = L2_1_0_array;
L2_3_min =  *IDX_PTR(L_Tmp12,double );
(L2_4_1_array)->st = L2_5_1_srg;
Midx_init_dim0(L2_4_1_array);
check_main_m0out(L1_m,L2_4_1_array);
Midx_m2sup(L1_m,L2_4_1_array,double ,double );
L_Tmp13 = L2_4_1_array;
L2_6_max =  *IDX_PTR(L_Tmp13,double );
(L2_2_array)->st = L2_2_srg;
RTERR_DIM(0 < 0 || 0 >= 2);
RTERR_DIM(1 < 0 || 1 >= 2);
Midx_init_dim2(L2_2_array, (L1_m)->dim[0],(L1_m)->dim[1]);
RTERR_DIM(L2_2_array->dim[0]<0);
RTERR_DIM(L2_2_array->dim[1]<0);
Midx_maclear(L2_2_array, unsigned char );
L2_7_img = L2_2_array;
{
bool L_Tmp14_malleable;
Midx_malleablep(L1_m,L_Tmp14_malleable);
 if (!(L_Tmp14_malleable)) { 
lush_error("index may not be reshaped");
 } 
{
index_t * L4_15_G475;
storage_t * L_Tmp16;
int L_Tmp17;
int L_Tmp18;
int L_Tmp19;
L_Tmp16 = ((L1_m)->st);
(L4_8_3_new_idx->dim[0]) = 1;
for(int i=(L1_m)->ndim-1; i>=0; i--) {

(L4_8_3_new_idx->dim[0]) *= (L1_m)->dim[i];
}
L4_8_3_new_idx->st = L_Tmp16;
L4_8_3_new_idx->ndim = 1;
L4_8_3_new_idx->offset = 0;
Midx_update_mod_from_dim(L4_8_3_new_idx);
L4_15_G475 = L4_8_3_new_idx;
L_Tmp18 = (int)(((2)-1));
RTERR_DIM(L_Tmp18 < 0 || L_Tmp18 >= 2);
L_Tmp17 = (L1_m)->mod[L_Tmp18];
{ ptrdiff_t old_val=Midx_mod(L4_15_G475,((int)0)); ptrdiff_t min_size, max_size;
Midx_mod(L4_15_G475,((int)0)) = ((int)L_Tmp17);
SRG_BOUNDS(L4_15_G475,1,min_size, max_size);
if((min_size < 0) || (max_size >= (ptrdiff_t)(L4_15_G475)->st->size)) {
Midx_mod(L4_15_G475,((int)0))= old_val;
RTERR_SRG_OVERFLOW;}}
L_Tmp19 = (L1_m)->offset;
{ ptrdiff_t old_val=Midx_offset(L4_15_G475); ptrdiff_t min_size, max_size;
Midx_offset(L4_15_G475) = ((int)L_Tmp19);
SRG_BOUNDS(L4_15_G475,1,min_size, max_size);
if((min_size < 0) || (max_size >= (ptrdiff_t)(L4_15_G475)->st->size)) {
Midx_offset(L4_15_G475)= old_val;
RTERR_SRG_OVERFLOW;}}
L2_9_mv = L4_15_G475;
}
}
L2_10_isrg = ((L2_7_img)->st);
L2_11_s = (((double)255)/((double)(L2_6_max-L2_3_min)));
{
int L3_20_i;
double L_Tmp21;
int L_Tmp22;
(L_Tmp22) = (int)L2_10_isrg->size;
L_Tmp21 = (L_Tmp22-1);
L3_20_i = 0;
for(;
((1>0)?(L3_20_i<=L_Tmp21):(L3_20_i>=L_Tmp21));
(L3_20_i)+=1 )
{
{
double L5_23_val;
unsigned char L_Tmp24;
RTERR_BOUND(L3_20_i<0 || L3_20_i>=((int )(L2_9_mv)->dim[0]));
L5_23_val = (IDX_PTR(L2_9_mv,double )[(L2_9_mv)->mod[0]*((int)L3_20_i)]-L2_3_min);
L_Tmp24 = (unsigned char)((L2_11_s*L5_23_val));
((unsigned char  *)(L2_10_isrg)->data)[(int)L3_20_i] = (L_Tmp24);
}
}
}
L_Tmp0 = L2_7_img;
Msrg_free(L2_2_0_srg);
Msrg_free(L2_5_1_srg);
}
TRACE_POP("C_as_image");
MM_EXIT; MM_ANCHOR(L_Tmp0); return L_Tmp0;
}
}

/* ---------------------------------------- */

#ifndef NOLISP

/* Declarations */
extern_c dhdoc_t K_popen_Rc8f18d7f;
extern_c dhdoc_t K_pnm_fread_rgb_R6defe29f;
extern_c dhdoc_t K_pclose_Rc7df00c0;
extern_c dhdoc_t K_pnm_fread_rgba_R6defe29f;
extern_c dhdoc_t K_pnm_fread_into_ubim_R2d01e887;
extern_c dhdoc_t K_pnm_fread_ubim_R6defe29f;
extern_c dhdoc_t K_ppm_fwrite_rgb_R2d01e887;
extern_c dhdoc_t K_pgm_fwrite_ubim_R2d01e887;


/*
 * STUB image-read-rgb
 */
DH(X_image_read_rgb)
{
dharg ret;
ret.dh_idx_ptr =  C_image_read_rgb(a[1].dh_str_ptr);
return ret;
}

/*
 * DHDOC image-read-rgb
 */
DHDOC(K_image_read_rgb_R592fa536,X_image_read_rgb,"C_image_read_rgb",0,0) = {
DH_FUNC(1),
DH_STR,
DH_RETURN,
DH_IDX(DHT_READ,3),
DH_SRG(DHT_READ),
DH_UCHAR,
DH_END_FUNC,
DH_REFER(K_popen_Rc8f18d7f),
DH_REFER(K_pnm_fread_rgb_R6defe29f),
DH_REFER(K_pclose_Rc7df00c0),
DH_NIL
};

/*
 * STUB image-read-rgba
 */
DH(X_image_read_rgba)
{
dharg ret;
ret.dh_idx_ptr =  C_image_read_rgba(a[1].dh_str_ptr);
return ret;
}

/*
 * DHDOC image-read-rgba
 */
DHDOC(K_image_read_rgba_R592fa536,X_image_read_rgba,"C_image_read_rgba",0,0) = {
DH_FUNC(1),
DH_STR,
DH_RETURN,
DH_IDX(DHT_READ,3),
DH_SRG(DHT_WRITE),
DH_UCHAR,
DH_END_FUNC,
DH_REFER(K_pnm_fread_rgba_R6defe29f),
DH_REFER(K_popen_Rc8f18d7f),
DH_REFER(K_pnm_fread_into_ubim_R2d01e887),
DH_REFER(K_pclose_Rc7df00c0),
DH_NIL
};

/*
 * STUB image-read-ubim
 */
DH(X_image_read_ubim)
{
dharg ret;
ret.dh_idx_ptr =  C_image_read_ubim(a[1].dh_str_ptr);
return ret;
}

/*
 * DHDOC image-read-ubim
 */
DHDOC(K_image_read_ubim_R592fa536,X_image_read_ubim,"C_image_read_ubim",0,0) = {
DH_FUNC(1),
DH_STR,
DH_RETURN,
DH_IDX(DHT_READ,2),
DH_SRG(DHT_READ),
DH_UCHAR,
DH_END_FUNC,
DH_REFER(K_popen_Rc8f18d7f),
DH_REFER(K_pnm_fread_ubim_R6defe29f),
DH_REFER(K_pclose_Rc7df00c0),
DH_NIL
};

/*
 * STUB image-write-rgb
 */
DH(X_image_write_rgb)
{
dharg ret;
ret.dh_bool =  C_image_write_rgb(a[1].dh_str_ptr, a[2].dh_idx_ptr);
return ret;
}

/*
 * DHDOC image-write-rgb
 */
DHDOC(K_image_write_rgb_R448167d5,X_image_write_rgb,"C_image_write_rgb",0,0) = {
DH_FUNC(2),
DH_STR,
DH_IDX(DHT_READ,3),
DH_SRG(DHT_READ),
DH_UCHAR,
DH_RETURN,
DH_BOOL,
DH_END_FUNC,
DH_REFER(K_popen_Rc8f18d7f),
DH_REFER(K_ppm_fwrite_rgb_R2d01e887),
DH_REFER(K_pclose_Rc7df00c0),
DH_NIL
};

/*
 * STUB image-write-ubim
 */
DH(X_image_write_ubim)
{
dharg ret;
ret.dh_bool =  C_image_write_ubim(a[1].dh_str_ptr, a[2].dh_idx_ptr);
return ret;
}

/*
 * DHDOC image-write-ubim
 */
DHDOC(K_image_write_ubim_R448167d5,X_image_write_ubim,"C_image_write_ubim",0,0) = {
DH_FUNC(2),
DH_STR,
DH_IDX(DHT_READ,2),
DH_SRG(DHT_READ),
DH_UCHAR,
DH_RETURN,
DH_BOOL,
DH_END_FUNC,
DH_REFER(K_popen_Rc8f18d7f),
DH_REFER(K_pgm_fwrite_ubim_R2d01e887),
DH_REFER(K_pclose_Rc7df00c0),
DH_NIL
};

/*
 * STUB as-image
 */
DH(X_as_image)
{
dharg ret;
ret.dh_idx_ptr =  C_as_image(a[1].dh_idx_ptr);
return ret;
}

/*
 * DHDOC as-image
 */
DHDOC(K_as_image_R59efa536,X_as_image,"C_as_image",0,0) = {
DH_FUNC(1),
DH_IDX(DHT_READ,2),
DH_SRG(DHT_READ),
DH_DOUBLE,
DH_RETURN,
DH_IDX(DHT_READ,2),
DH_SRG(DHT_READ),
DH_UCHAR,
DH_END_FUNC,
DH_NIL
};

/*
 * INIT FUNCTION
 */
extern_c void init_image_io(void)
{
 dh_define("image-read-rgb", &K_image_read_rgb_R592fa536); 
 dh_define("image-read-rgba", &K_image_read_rgba_R592fa536); 
 dh_define("image-read-ubim", &K_image_read_ubim_R592fa536); 
 dh_define("image-write-rgb", &K_image_write_rgb_R448167d5); 
 dh_define("image-write-ubim", &K_image_write_ubim_R448167d5); 
 dh_define("as-image", &K_as_image_R59efa536); 
}

int majver_image_io = 50;
int minver_image_io = 01;


#endif

