/***
*fstream.h - definitions/declarations for filebuf and fstream classes
*
*       Copyright (c) Microsoft Corporation.  All rights reserved.
*
*Purpose:
*       This file defines the classes, values, macros, and functions
*       used by the filebuf and fstream classes.
*       [AT&T C++]
*
*       [Public]
*
****/

#if     _MSC_VER > 1000
#pragma once
#endif

#ifdef  __cplusplus

#ifndef _INC_FSTREAM
#define _INC_FSTREAM

#if     !defined(_WIN32)
#error ERROR: Only Win32 target supported!
#endif


#ifdef  _MSC_VER
// Currently, all MS C compilers for Win32 platforms default to 8 byte
// alignment.
#pragma pack(push,8)

#include <useoldio.h>

#endif  // _MSC_VER

#include <crtdefs.h>
#include <iostream.h>

#ifdef  _MSC_VER
// C4514: "unreferenced inline function has been removed"
#pragma warning(disable:4514) // disable C4514 warning
// #pragma warning(default:4514)        // use this to reenable, if desired
#endif  // _MSC_VER

typedef int filedesc;

class _CRTIMP filebuf : public streambuf {
public:
static  const int       openprot;       // default share/prot mode for open

// optional share values for 3rd argument (prot) of open or constructor
static  const int       sh_none;        // exclusive mode no sharing
static  const int       sh_read;        // allow read sharing
static  const int       sh_write;       // allow write sharing
// use (sh_read | sh_write) to allow both read and write sharing

// options for setmode member function
static  const int       binary;
static  const int       text;

                        filebuf();
                        filebuf(filedesc);
                        filebuf(filedesc, _In_z_ char *, int);
                        ~filebuf();

        filebuf*        attach(filedesc);
        filedesc        fd() const { return (x_fd==-1) ? EOF : x_fd; }
        int             is_open() const { return (x_fd!=-1); }
        filebuf*        open(const char *, int, int = filebuf::openprot);
        filebuf*        close();
        int             setmode(int = filebuf::text);

virtual int             overflow(int=EOF);
virtual int             underflow();

virtual streambuf*      setbuf(_In_opt_z_ char *, int);
virtual streampos       seekoff(streamoff, ios::seek_dir, int);
// virtual      streampos       seekpos(streampos, int);
virtual int             sync();

private:
        filedesc        x_fd;
        int             x_fOpened;
};

class _CRTIMP ifstream : public istream {
public:
        ifstream();
        ifstream(const char *, int =ios::in, int = filebuf::openprot);
        ifstream(filedesc);
        ifstream(filedesc, _In_opt_z_ char *, int);
        ~ifstream();

        streambuf * setbuf(_In_opt_z_ char *, int);
        filebuf* rdbuf() const { return (filebuf*) ios::rdbuf(); }

        void attach(filedesc);
        filedesc fd() const { return rdbuf()->fd(); }

        int is_open() const { return rdbuf()->is_open(); }
        void open(const char *, int =ios::in, int = filebuf::openprot);
        void close();
        int setmode(int mode = filebuf::text) { return rdbuf()->setmode(mode); }
};

class _CRTIMP ofstream : public ostream {
public:
        ofstream();
        ofstream(const char *, int =ios::out, int = filebuf::openprot);
        ofstream(filedesc);
        ofstream(filedesc, _In_opt_z_ char *, int);
        ~ofstream();

        streambuf * setbuf(_In_opt_z_ char *, int);
        filebuf* rdbuf() const { return (filebuf*) ios::rdbuf(); }

        void attach(filedesc);
        filedesc fd() const { return rdbuf()->fd(); }

        int is_open() const { return rdbuf()->is_open(); }
        void open(const char *, int =ios::out, int = filebuf::openprot);
        void close();
        int setmode(int mode = filebuf::text) { return rdbuf()->setmode(mode); }
};
        
class _CRTIMP fstream : public iostream {
public:
        fstream();
        fstream(const char *, int, int = filebuf::openprot);
        fstream(filedesc);
        fstream(filedesc, _In_opt_z_ char *, int);
        ~fstream();

        streambuf * setbuf(_In_opt_z_ char *, int);
        filebuf* rdbuf() const { return (filebuf*) ostream::rdbuf(); }

        void attach(filedesc);
        filedesc fd() const { return rdbuf()->fd(); }

        int is_open() const { return rdbuf()->is_open(); }
        void open(const char *, int, int = filebuf::openprot);
        void close();
        int setmode(int mode = filebuf::text) { return rdbuf()->setmode(mode); }
};
        
// manipulators to dynamically change file access mode (filebufs only)
inline  ios& binary(ios& _fstrm) \
   { ((filebuf*)_fstrm.rdbuf())->setmode(filebuf::binary); return _fstrm; }
inline  ios& text(ios& _fstrm) \
   { ((filebuf*)_fstrm.rdbuf())->setmode(filebuf::text); return _fstrm; }

#ifdef  _MSC_VER
#pragma pack(pop)
#endif  // _MSC_VER

#endif  // _INC_FSTREAM

#endif  /* __cplusplus */
/* 88bf0570-3001-4e78-a5f2-be5765546192 */ 
