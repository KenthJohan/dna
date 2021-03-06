#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "iup.h"
#include "iupcontrols.h"
#include "iupcbs.h"

#include "csc/csc_malloc_file.h"
#include "csc/csc_tcol.h"

//http://oregonstate.edu/instruct/bb331/lecture02/lecture02.html

#define CODON_START "atg"
#define CODON_STOP1 "taa"
#define CODON_STOP2 "tag"
#define CODON_STOP3 "tga"

void highlight (char const * dna)
{
	char const * p = dna;
	while (p[0])
	{
		if (memcmp (p, CODON_START, 3) == 0)
		{
			fputs (TCOL (TCOL_NORMAL, TCOL_GREEN, TCOL_DEFAULT), stdout);
			fwrite (p, sizeof (char), 3, stdout);
			fputs (TCOL_RST, stdout);
			p += 3;
		}
		else if (memcmp (p, CODON_STOP1, 3) == 0)
		{
			fputs (TCOL (TCOL_NORMAL, TCOL_RED, TCOL_DEFAULT), stdout);
			fwrite (p, sizeof (char), 3, stdout);
			fputs (TCOL_RST, stdout);
			p += 3;
		}
		else if (memcmp (p, CODON_STOP2, 3) == 0)
		{
			fputs (TCOL (TCOL_NORMAL, TCOL_RED, TCOL_DEFAULT), stdout);
			fwrite (p, sizeof (char), 3, stdout);
			fputs (TCOL_RST, stdout);
			p += 3;
		}
		else if (memcmp (p, CODON_STOP3, 3) == 0)
		{
			fputs (TCOL (TCOL_NORMAL, TCOL_RED, TCOL_DEFAULT), stdout);
			fwrite (p, sizeof (char), 3, stdout);
			fputs (TCOL_RST, stdout);
			p += 3;
		}
		else
		{
			putc (p[0], stdout);
			p += 1;
		}
		if (((uintptr_t)p & 31) == 0)
		{
			putc ('\n', stdout);
		}
		else if (((uintptr_t)p & 7) == 0)
		{
			putc (' ', stdout);
		}
	}
}

static Ihandle* create_matrix (void)
{
	char * dna = csc_malloc_file ("../dna/sars.txt");
	highlight (dna);
	fflush (stdout);

	Ihandle* mat = IupMatrix(NULL);
	IupSetAttribute(mat, "NUMLIN", "4");
	IupSetAttribute(mat, "NUMCOL", "8");
	IupSetAttribute(mat, "1:1", "5.6\n3.33");
	IupSetAttribute(mat, "2:1", "2.2");
	IupSetAttribute(mat, "3:2", "Very Very Very Very Very Large Text");
	IupSetAttribute(mat, "1:2", "4.5");
	IupSetAttribute(mat, "3:1", "3.4");
	IupSetAttribute(mat, "3:3", "Font Test");
	IupSetAttribute(mat,"SORTSIGN2","DOWN");
	IupSetAttribute(mat,"RESIZEMATRIX", "YES");
	IupSetAttribute(mat, "FONT3:3", "Helvetica, 24");
	IupSetAttribute(mat, "MASK*:3", "[a-zA-Z][0-9a-zA-Z_]*");
	IupSetAttribute(mat, "TYPE4:1", "COLOR");
	IupSetAttribute(mat, "4:1", "255 0 128");
	IupSetAttribute(mat, "TYPE4:2", "FILL");
	IupSetAttribute(mat, "4:2", "60");
	IupSetAttribute(mat, "SHOWFILLVALUE", "Yes");
	IupSetAttribute(mat, "TOGGLECENTERED", "Yes");
	IupSetAttribute(mat,"MARKMODE","CELL");
	IupSetAttribute(mat,"MARKMULTIPLE","YES");
	IupSetAttribute(mat,"FRAMEVERTCOLOR1:2","BGCOLOR");
	IupSetAttribute(mat,"FRAMEHORIZCOLOR1:2","0 0 255");
	IupSetAttribute(mat,"FRAMEHORIZCOLOR1:3","0 255 0");
	IupSetAttribute(mat,"FRAMEVERTCOLOR2:2","255 255 0");
	IupSetAttribute(mat,"FRAMEVERTCOLOR*:4","0 255 0");
	IupSetAttribute(mat,"FRAMEVERTCOLOR*:5","BGCOLOR");
	IupSetAttribute(mat, "20:8", "The End");
	IupSetAttribute(mat, "NUMCOL_VISIBLE", "3");
	IupSetAttribute(mat, "NUMLIN_VISIBLE", "5");
	return mat;
}

void MatrixTest(void)
{
	Ihandle* dlg, *box, *mat;
	box = IupVbox(mat = create_matrix(), NULL);
	IupSetAttribute(box, "MARGIN", "10x10");
	dlg = IupDialog(box);
	IupSetAttribute(dlg, "TITLE", "IupMatrix Simple Test");
	IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
}


int main(int argc, char* argv[])
{
	IupOpen(&argc, &argv);
	IupControlsOpen();
	MatrixTest();
	IupMainLoop();
	IupClose();
	return EXIT_SUCCESS;
}

