/* soapStub.h
   Generated by gSOAP 2.8.40 for pdaWs.h

gSOAP XML Web services tools
Copyright (C) 2000-2016, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include <deque>
#include <list>
#include <vector>
#include <set>
#define SOAP_NAMESPACE_OF_ns1	"http://ws.stcs.itms.boco.com/"

#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"
#if GSOAP_VERSION != 20840
# error "GSOAP VERSION 20840 MISMATCH IN GENERATED CODE VERSUS LIBRARY CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes, Structs and Unions                                                *
 *                                                                            *
\******************************************************************************/

class ns1__getPdaInfo;	/* pdaWs.h:147 */
class ns1__getPdaInfoResponse;	/* pdaWs.h:150 */
class ns1__DocumentException;	/* pdaWs.h:153 */
struct __ns1__getPdaInfo;	/* pdaWs.h:409 */

/* pdaWs.h:147 */
#ifndef SOAP_TYPE_ns1__getPdaInfo
#define SOAP_TYPE_ns1__getPdaInfo (11)
/* complex XSD type 'ns1:getPdaInfo': */
class SOAP_CMAC ns1__getPdaInfo {
      public:
        /// Optional element 'pdaInfo' of XSD type 'xsd:string'
        std::string *pdaInfo;
        /// Context that manages this object
        struct soap *soap;
      public:
        /// Return unique type id SOAP_TYPE_ns1__getPdaInfo
        virtual int soap_type(void) const { return SOAP_TYPE_ns1__getPdaInfo; }
        /// (Re)set members to default values
        virtual void soap_default(struct soap*);
        /// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
        virtual void soap_serialize(struct soap*) const;
        /// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
        virtual int soap_put(struct soap*, const char *tag, const char *type) const;
        /// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
        virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
        /// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
        virtual void *soap_get(struct soap*, const char *tag, const char *type);
        /// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
        virtual void *soap_in(struct soap*, const char *tag, const char *type);
        /// Return a new object of type ns1__getPdaInfo, default initialized and not managed by a soap context
        virtual ns1__getPdaInfo *soap_alloc(void) const { return SOAP_NEW(ns1__getPdaInfo); }
      public:
        /// Constructor with initializations
        ns1__getPdaInfo()
        {
          pdaInfo = (std::string *)0;
          soap = (struct soap *)0;
        }
        virtual ~ns1__getPdaInfo() { }
        /// Friend allocator used by soap_new_ns1__getPdaInfo(struct soap*, int)
        friend SOAP_FMAC1 ns1__getPdaInfo * SOAP_FMAC2 soap_instantiate_ns1__getPdaInfo(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* pdaWs.h:150 */
#ifndef SOAP_TYPE_ns1__getPdaInfoResponse
#define SOAP_TYPE_ns1__getPdaInfoResponse (12)
/* complex XSD type 'ns1:getPdaInfoResponse': */
class SOAP_CMAC ns1__getPdaInfoResponse {
      public:
        /// Optional element 'result' of XSD type 'xsd:string'
        std::string *result;
        /// Context that manages this object
        struct soap *soap;
      public:
        /// Return unique type id SOAP_TYPE_ns1__getPdaInfoResponse
        virtual int soap_type(void) const { return SOAP_TYPE_ns1__getPdaInfoResponse; }
        /// (Re)set members to default values
        virtual void soap_default(struct soap*);
        /// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
        virtual void soap_serialize(struct soap*) const;
        /// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
        virtual int soap_put(struct soap*, const char *tag, const char *type) const;
        /// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
        virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
        /// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
        virtual void *soap_get(struct soap*, const char *tag, const char *type);
        /// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
        virtual void *soap_in(struct soap*, const char *tag, const char *type);
        /// Return a new object of type ns1__getPdaInfoResponse, default initialized and not managed by a soap context
        virtual ns1__getPdaInfoResponse *soap_alloc(void) const { return SOAP_NEW(ns1__getPdaInfoResponse); }
      public:
        /// Constructor with initializations
        ns1__getPdaInfoResponse()
        {
          result = (std::string *)0;
          soap = (struct soap *)0;
        }
        virtual ~ns1__getPdaInfoResponse() { }
        /// Friend allocator used by soap_new_ns1__getPdaInfoResponse(struct soap*, int)
        friend SOAP_FMAC1 ns1__getPdaInfoResponse * SOAP_FMAC2 soap_instantiate_ns1__getPdaInfoResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* pdaWs.h:153 */
#ifndef SOAP_TYPE_ns1__DocumentException
#define SOAP_TYPE_ns1__DocumentException (13)
/* complex XSD type 'ns1:DocumentException': */
class SOAP_CMAC ns1__DocumentException {
      public:
        /// Optional element 'message' of XSD type 'xsd:string'
        std::string *message;
        /// Optional element 'message' of XSD type 'xsd:string'
        std::string *message_;
        /// Context that manages this object
        struct soap *soap;
      public:
        /// Return unique type id SOAP_TYPE_ns1__DocumentException
        virtual int soap_type(void) const { return SOAP_TYPE_ns1__DocumentException; }
        /// (Re)set members to default values
        virtual void soap_default(struct soap*);
        /// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
        virtual void soap_serialize(struct soap*) const;
        /// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
        virtual int soap_put(struct soap*, const char *tag, const char *type) const;
        /// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
        virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
        /// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
        virtual void *soap_get(struct soap*, const char *tag, const char *type);
        /// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
        virtual void *soap_in(struct soap*, const char *tag, const char *type);
        /// Return a new object of type ns1__DocumentException, default initialized and not managed by a soap context
        virtual ns1__DocumentException *soap_alloc(void) const { return SOAP_NEW(ns1__DocumentException); }
      public:
        /// Constructor with initializations
        ns1__DocumentException()
        {
          message = (std::string *)0;
          message_ = (std::string *)0;
          soap = (struct soap *)0;
        }
        virtual ~ns1__DocumentException() { }
        /// Friend allocator used by soap_new_ns1__DocumentException(struct soap*, int)
        friend SOAP_FMAC1 ns1__DocumentException * SOAP_FMAC2 soap_instantiate_ns1__DocumentException(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* pdaWs.h:323 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (17)
/* SOAP_ENV__Detail: */
struct SOAP_CMAC SOAP_ENV__Detail {
      public:
        /** Optional element 'ns1:DocumentException' of XSD type 'ns1:DocumentException' */
        ns1__DocumentException *ns1__DocumentException_;
        /** Any type of element 'fault' assigned to fault with its SOAP_TYPE_T assigned to __type */
        /** Do not create a cyclic data structure throught this member unless SOAP encoding or SOAP_XML_GRAPH are used for id-ref serialization */
        int __type;
        void *fault;
        char *__any;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Detail */
        int soap_type() const { return SOAP_TYPE_SOAP_ENV__Detail; }
        /** Constructor with member initializations */
        SOAP_ENV__Detail()
        {
          ns1__DocumentException_ = (ns1__DocumentException *)0;
          __type = 0;
          fault = NULL;
          __any = (char *)0;
        }
        /** Friend allocator used by soap_new_SOAP_ENV__Detail(struct soap*, int) */
        friend SOAP_FMAC1 SOAP_ENV__Detail * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* pdaWs.h:409 */
#ifndef SOAP_TYPE___ns1__getPdaInfo
#define SOAP_TYPE___ns1__getPdaInfo (24)
/* Wrapper: */
struct SOAP_CMAC __ns1__getPdaInfo {
      public:
        /** Optional element 'ns1:getPdaInfo' of XSD type 'ns1:getPdaInfo' */
        ns1__getPdaInfo *ns1__getPdaInfo_;
      public:
        /** Return unique type id SOAP_TYPE___ns1__getPdaInfo */
        int soap_type() const { return SOAP_TYPE___ns1__getPdaInfo; }
        /** Constructor with member initializations */
        __ns1__getPdaInfo()
        {
          ns1__getPdaInfo_ = (ns1__getPdaInfo *)0;
        }
        /** Friend allocator used by soap_new___ns1__getPdaInfo(struct soap*, int) */
        friend SOAP_FMAC1 __ns1__getPdaInfo * SOAP_FMAC2 soap_instantiate___ns1__getPdaInfo(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* pdaWs.h:476 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (25)
/* SOAP_ENV__Header: */
struct SOAP_CMAC SOAP_ENV__Header {
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Header */
        int soap_type() const { return SOAP_TYPE_SOAP_ENV__Header; }
        /** Constructor with member initializations */
        SOAP_ENV__Header()
        {
        }
        /** Friend allocator used by soap_new_SOAP_ENV__Header(struct soap*, int) */
        friend SOAP_FMAC1 SOAP_ENV__Header * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* pdaWs.h:476 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (26)
/* Type SOAP_ENV__Code is a recursive data type, (in)directly referencing itself through its (base or derived class) members */
/* SOAP_ENV__Code: */
struct SOAP_CMAC SOAP_ENV__Code {
      public:
        /** Optional element 'SOAP-ENV:Value' of XSD type 'xsd:QName' */
        char *SOAP_ENV__Value;
        /** Optional element 'SOAP-ENV:Subcode' of XSD type 'SOAP-ENV:Code' */
        struct SOAP_ENV__Code *SOAP_ENV__Subcode;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Code */
        int soap_type() const { return SOAP_TYPE_SOAP_ENV__Code; }
        /** Constructor with member initializations */
        SOAP_ENV__Code()
        {
          SOAP_ENV__Value = (char *)0;
          SOAP_ENV__Subcode = (struct SOAP_ENV__Code *)0;
        }
        /** Friend allocator used by soap_new_SOAP_ENV__Code(struct soap*, int) */
        friend SOAP_FMAC1 SOAP_ENV__Code * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* pdaWs.h:476 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (28)
/* SOAP_ENV__Reason: */
struct SOAP_CMAC SOAP_ENV__Reason {
      public:
        /** Optional element 'SOAP-ENV:Text' of XSD type 'xsd:string' */
        char *SOAP_ENV__Text;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Reason */
        int soap_type() const { return SOAP_TYPE_SOAP_ENV__Reason; }
        /** Constructor with member initializations */
        SOAP_ENV__Reason()
        {
          SOAP_ENV__Text = (char *)0;
        }
        /** Friend allocator used by soap_new_SOAP_ENV__Reason(struct soap*, int) */
        friend SOAP_FMAC1 SOAP_ENV__Reason * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* pdaWs.h:476 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (29)
/* SOAP_ENV__Fault: */
struct SOAP_CMAC SOAP_ENV__Fault {
      public:
        /** Optional element 'faultcode' of XSD type 'xsd:QName' */
        char *faultcode;
        /** Optional element 'faultstring' of XSD type 'xsd:string' */
        char *faultstring;
        /** Optional element 'faultactor' of XSD type 'xsd:string' */
        char *faultactor;
        /** Optional element 'detail' of XSD type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *detail;
        /** Optional element 'SOAP-ENV:Code' of XSD type 'SOAP-ENV:Code' */
        struct SOAP_ENV__Code *SOAP_ENV__Code;
        /** Optional element 'SOAP-ENV:Reason' of XSD type 'SOAP-ENV:Reason' */
        struct SOAP_ENV__Reason *SOAP_ENV__Reason;
        /** Optional element 'SOAP-ENV:Node' of XSD type 'xsd:string' */
        char *SOAP_ENV__Node;
        /** Optional element 'SOAP-ENV:Role' of XSD type 'xsd:string' */
        char *SOAP_ENV__Role;
        /** Optional element 'SOAP-ENV:Detail' of XSD type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *SOAP_ENV__Detail;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Fault */
        int soap_type() const { return SOAP_TYPE_SOAP_ENV__Fault; }
        /** Constructor with member initializations */
        SOAP_ENV__Fault()
        {
          faultcode = (char *)0;
          faultstring = (char *)0;
          faultactor = (char *)0;
          detail = (struct SOAP_ENV__Detail *)0;
          SOAP_ENV__Code = (struct SOAP_ENV__Code *)0;
          SOAP_ENV__Reason = (struct SOAP_ENV__Reason *)0;
          SOAP_ENV__Node = (char *)0;
          SOAP_ENV__Role = (char *)0;
          SOAP_ENV__Detail = (struct SOAP_ENV__Detail *)0;
        }
        /** Friend allocator used by soap_new_SOAP_ENV__Fault(struct soap*, int) */
        friend SOAP_FMAC1 SOAP_ENV__Fault * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/


/* pdaWs.h:101 */
#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

/* pdaWs.h:101 */
#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif

/******************************************************************************\
 *                                                                            *
 * Serializable Types                                                         *
 *                                                                            *
\******************************************************************************/


/* char has binding name 'byte' for type 'xsd:byte' */
#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif

/* int has binding name 'int' for type 'xsd:int' */
#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif

/* std::string has binding name 'std__string' for type 'xsd:string' */
#ifndef SOAP_TYPE_std__string
#define SOAP_TYPE_std__string (14)
#endif

/* ns1__DocumentException has binding name 'ns1__DocumentException' for type 'ns1:DocumentException' */
#ifndef SOAP_TYPE_ns1__DocumentException
#define SOAP_TYPE_ns1__DocumentException (13)
#endif

/* ns1__getPdaInfoResponse has binding name 'ns1__getPdaInfoResponse' for type 'ns1:getPdaInfoResponse' */
#ifndef SOAP_TYPE_ns1__getPdaInfoResponse
#define SOAP_TYPE_ns1__getPdaInfoResponse (12)
#endif

/* ns1__getPdaInfo has binding name 'ns1__getPdaInfo' for type 'ns1:getPdaInfo' */
#ifndef SOAP_TYPE_ns1__getPdaInfo
#define SOAP_TYPE_ns1__getPdaInfo (11)
#endif

/* struct SOAP_ENV__Fault has binding name 'SOAP_ENV__Fault' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (29)
#endif

/* struct SOAP_ENV__Reason has binding name 'SOAP_ENV__Reason' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (28)
#endif

/* struct SOAP_ENV__Code has binding name 'SOAP_ENV__Code' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (26)
#endif

/* struct SOAP_ENV__Header has binding name 'SOAP_ENV__Header' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (25)
#endif

/* struct SOAP_ENV__Detail has binding name 'SOAP_ENV__Detail' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (17)
#endif

/* struct SOAP_ENV__Reason * has binding name 'PointerToSOAP_ENV__Reason' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (31)
#endif

/* struct SOAP_ENV__Detail * has binding name 'PointerToSOAP_ENV__Detail' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (30)
#endif

/* struct SOAP_ENV__Code * has binding name 'PointerToSOAP_ENV__Code' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (27)
#endif

/* ns1__getPdaInfo * has binding name 'PointerTons1__getPdaInfo' for type 'ns1:getPdaInfo' */
#ifndef SOAP_TYPE_PointerTons1__getPdaInfo
#define SOAP_TYPE_PointerTons1__getPdaInfo (21)
#endif

/* ns1__DocumentException * has binding name 'PointerTons1__DocumentException' for type 'ns1:DocumentException' */
#ifndef SOAP_TYPE_PointerTons1__DocumentException
#define SOAP_TYPE_PointerTons1__DocumentException (18)
#endif

/* std::string * has binding name 'PointerTostd__string' for type 'xsd:string' */
#ifndef SOAP_TYPE_PointerTostd__string
#define SOAP_TYPE_PointerTostd__string (15)
#endif

/* _XML has binding name '_XML' for type '' */
#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
#endif

/* _QName has binding name '_QName' for type 'xsd:QName' */
#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
#endif

/* char * has binding name 'string' for type 'xsd:string' */
#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif

/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of soapStub.h */