/*
* Copyright (c) 2017-2018, Intel Corporation
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:

* 1. Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
* 3. Neither the name of the copyright holder nor the names of its contributors
*    may be used to endorse or promote products derived from this software
*    without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
* OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
* OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
extern "C" {
#ifndef SGX_ECDSA_QUOTE_VERIFICATION_H_
#define SGX_ECDSA_QUOTE_VERIFICATION_H_

#define QVL_API __attribute__ ((visibility("default")))

#include <stddef.h>
#include <stdint.h>

/**
 * @file
 * @defgroup group_main QuoteVerification.h
 * This is the main entry point for the ECDSA Quote Verification Library.
 * Use the provided functions to perform various verifications tasks.
 * @{
 */

/**
 * List of possible status code values of the Quote Verification Library functions.
 * Status codes indicate the result of an operation.
 */
typedef enum _status
{
    STATUS_OK = 0,

    STATUS_UNSUPPORTED_CERT_FORMAT,

    STATUS_SGX_ROOT_CA_MISSING,
    STATUS_SGX_ROOT_CA_INVALID,
    STATUS_SGX_ROOT_CA_INVALID_EXTENSIONS,
    STATUS_SGX_ROOT_CA_INVALID_ISSUER,
    STATUS_SGX_ROOT_CA_UNTRUSTED,

    STATUS_SGX_INTERMEDIATE_CA_MISSING,
    STATUS_SGX_INTERMEDIATE_CA_INVALID,
    STATUS_SGX_INTERMEDIATE_CA_INVALID_EXTENSIONS,
    STATUS_SGX_INTERMEDIATE_CA_INVALID_ISSUER, // 10
    STATUS_SGX_INTERMEDIATE_CA_REVOKED,

    STATUS_SGX_PCK_MISSING,
    STATUS_SGX_PCK_INVALID,
    STATUS_SGX_PCK_INVALID_EXTENSIONS,
    STATUS_SGX_PCK_INVALID_ISSUER,
    STATUS_SGX_PCK_REVOKED,

    STATUS_TRUSTED_ROOT_CA_INVALID,
    STATUS_SGX_PCK_CERT_CHAIN_UNTRUSTED,

    STATUS_SGX_TCB_INFO_UNSUPPORTED_FORMAT,
    STATUS_SGX_TCB_INFO_INVALID,            // 20
    STATUS_TCB_INFO_INVALID_SIGNATURE,

    STATUS_SGX_TCB_SIGNING_CERT_MISSING,
    STATUS_SGX_TCB_SIGNING_CERT_INVALID,
    STATUS_SGX_TCB_SIGNING_CERT_INVALID_EXTENSIONS,
    STATUS_SGX_TCB_SIGNING_CERT_INVALID_ISSUER,
    STATUS_SGX_TCB_SIGNING_CERT_CHAIN_UNTRUSTED,
    STATUS_SGX_TCB_SIGNING_CERT_REVOKED,

    STATUS_SGX_CRL_UNSUPPORTED_FORMAT,
    STATUS_SGX_CRL_UNKNOWN_ISSUER,
    STATUS_SGX_CRL_INVALID,                 // 30
    STATUS_SGX_CRL_INVALID_EXTENSIONS,
    STATUS_SGX_CRL_INVALID_SIGNATURE,


    STATUS_SGX_CA_CERT_UNSUPPORTED_FORMAT,
    STATUS_SGX_CA_CERT_INVALID,
    STATUS_TRUSTED_ROOT_CA_UNSUPPORTED_FORMAT,

    STATUS_MISSING_PARAMETERS,

    STATUS_UNSUPPORTED_QUOTE_FORMAT,
    STATUS_UNSUPPORTED_PCK_CERT_FORMAT,
    STATUS_INVALID_PCK_CERT,
    STATUS_UNSUPPORTED_PCK_RL_FORMAT,        // 40
    STATUS_INVALID_PCK_CRL,
    STATUS_UNSUPPORTED_TCB_INFO_FORMAT,
    STATUS_PCK_REVOKED,
    STATUS_TCB_INFO_MISMATCH,
    STATUS_TCB_OUT_OF_DATE,
    STATUS_TCB_REVOKED,
    STATUS_TCB_CONFIGURATION_NEEDED,
    STATUS_TCB_NOT_SUPPORTED,
    STATUS_TCB_UNRECOGNIZED_STATUS,
    STATUS_UNSUPPORTED_QE_CERTIFICATION,     // 50
    STATUS_INVALID_QE_CERTIFICATION_DATA_SIZE,
    STATUS_UNSUPPORTED_QE_CERTIFICATION_DATA_TYPE,
    STATUS_PCK_CERT_MISMATCH,
    STATUS_INVALID_QE_REPORT_SIGNATURE,
    STATUS_INVALID_QE_REPORT_DATA,
    STATUS_INVALID_QUOTE_SIGNATURE,

    STATUS_SGX_QE_IDENTITY_UNSUPPORTED_FORMAT,
    STATUS_SGX_QE_IDENTITY_INVALID,
    STATUS_SGX_QE_IDENTITY_INVALID_SIGNATURE,

    STATUS_SGX_ENCLAVE_REPORT_UNSUPPORTED_FORMAT,    // 60
    STATUS_SGX_ENCLAVE_IDENTITY_UNSUPPORTED_FORMAT,
    STATUS_SGX_ENCLAVE_IDENTITY_INVALID,
    STATUS_SGX_ENCLAVE_IDENTITY_UNSUPPORTED_VERSION,
    STATUS_SGX_ENCLAVE_IDENTITY_OUT_OF_DATE,
    STATUS_SGX_ENCLAVE_REPORT_MISCSELECT_MISMATCH,
    STATUS_SGX_ENCLAVE_REPORT_ATTRIBUTES_MISMATCH,
    STATUS_SGX_ENCLAVE_REPORT_MRENCLAVE_MISMATCH,
    STATUS_SGX_ENCLAVE_REPORT_MRSIGNER_MISMATCH,
    STATUS_SGX_ENCLAVE_REPORT_ISVPRODID_MISMATCH,
    STATUS_SGX_ENCLAVE_REPORT_ISVSVN_OUT_OF_DATE,   // 70

    STATUS_UNSUPPORTED_QE_IDENTITY_FORMAT,
    STATUS_QE_IDENTITY_OUT_OF_DATE,
    STATUS_QE_IDENTITY_MISMATCH
} Status;

/**
 * This function is responsible for verifying provided quote against PCK certificates. 
 *
 * @param quote - Buffer with serialized quote structure.
 * @param quoteSize - Size of quote buffer. Function heavily relies on this input as internal buffer is allocated based on it without boundaries check! It's user responsibility to provide proper validation.
 * @param pemPckCertificate - Null terminated Intel SGX PCK certificate in PEM format.
 * @param intermediateCrl - Null terminated, PEM formatted x.509 Intel SGX PCK Processor/Platform CRL
 * @param tcbInfoJson - TCB Info structure in JSON format signed by Intel SGX TCB Signing Certificate.
 * @return Status code of the operation, one of:
 *      - STATUS_OK
 *      - STATUS_MISSING_PARAMETERS
 *      - STATUS_UNSUPPORTED_QUOTE_FORMAT
 *      - STATUS_UNSUPPORTED_PCK_CERT_FORMAT
 *      - STATUS_INVALID_PCK_CERT
 *      - STATUS_UNSUPPORTED_PCK_RL_FORMAT
 *      - STATUS_INVALID_PCK_RL
 *      - STATUS_PCK_REVOKED
 *      - STATUS_UNSUPPORTED_TCB_INFO_FORMAT
 *      - STATUS_TCB_INFO_MISMATCH
 *      - STATUS_TCB_OUT_OF_DATE
 *      - STATUS_TCB_REVOKED
 *      - STATUS_UNSUPPORTED_QE_CERTIFICATION
 *      - STATUS_PCK_CERT_MISMATCH
 *      - STATUS_INVALID_QE_REPORT_SIGNATURE
 *      - STATUS_INVALID_QE_REPORT_DATA
 *      - STATUS_INVALID_QUOTE_SIGNATURE
 */
QVL_API Status sgxAttestationVerifyQuote(const uint8_t* quote, uint32_t quoteSize, const char *pemPckCertificate, const char* intermediateCrl, const char* tcbInfoJson, const char* qeIdentityJson);

/**
 *
 * @param enclaveReport - Buffer with serialized Enclave Report  structure.
 * @param enclaveIdentity - Enclave Identity structure in JSON format.
 * @return Status code of the operation, one of:
 *      - STATUS_OK
 *      - STATUS_SGX_ENCLAVE_REPORT_UNSUPPORTED_FORMAT
 *      - STATUS_SGX_ENCLAVE_IDENTITY_UNSUPPORTED_FORMAT
 *      - STATUS_SGX_ENCLAVE_IDENTITY_INVALID
 *      - STATUS_SGX_ENCLAVE_IDENTITY_UNSUPPORTED_VERSION
 *      - STATUS_SGX_ENCLAVE_IDENTITY_OUT_OF_DATE
 *      - STATUS_SGX_ENCLAVE_REPORT_MISCSELECT_MISMATCH
 *      - STATUS_SGX_ENCLAVE_REPORT_ATTRIBUTES_MISMATCH
 *      - STATUS_SGX_ENCLAVE_REPORT_MRENCLAVE_MISMATCH
 *      - STATUS_SGX_ENCLAVE_REPORT_MRSIGNER_MISMATCH
 *      - STATUS_SGX_ENCLAVE_REPORT_ISVPRODID_MISMATCH
 *      - STATUS_SGX_ENCLAVE_REPORT_ISVSVN_OUT_OF_DATE
 */

QVL_API Status sgxAttestationVerifyEnclaveReport(const uint8_t* enclaveReport, const char* enclaveIdentity);
/**
 * This function returns version information.
 *
 * @return Returned c-string includes:
 *  	- API version (changed when Quote Verification Library API is modified)
 */
QVL_API const char* sgxAttestationGetVersion(void);

/**
 * This function returns size of QE Certification Data (part of Quote Auth Data) retrieved from provided Quote.
 * @param quote - Buffer with serialized quote structure.
 * @param quoteSize - Size of quote buffer. Function heavily relies on this input as internal buffer is allocated based on it without boundaries check! It's user responsibility to provide proper validation.
 * @param qeCertificateDataSize - Size of QE Certification Data retrieved from Quote. Out parameter - will hold the size.
 * @return Status code of the operation. One of:
 *      - STATUS_OK
 *      - STATUS_MISSING_PARAMETERS
 *      - STATUS_UNSUPPORTED_QUOTE_FORMAT
 */
QVL_API Status sgxAttestationGetQECertificationDataSize(
        const uint8_t *quote,
        uint32_t quoteSize,
        uint32_t *qeCertificationDataSize);

/**
 * This function returns QE Certification Data Type and buffer with QE Certification Data retrieved from provided Quote.
 *
 * @param quote - Buffer with serialized quote structure.
 * @param quoteSize - Size of quote buffer. Function heavily relies on this input as internal buffer is allocated based on it without boundaries check! It's user responsibility to provide proper validation.
 * @param qeCertificateDataSize - Size of QE Certification Data retrieved from Quote.
 * @param qeCertificationData - Reference to buffer for QE Certification Data retrieved from Quote. Out parameter - will hold extracted QE Cert data.
 * @param qeCertificationDataType - Enum representing type of QE Certification Data. Out parameter - will hold the type. One of:
 *      - Plain PCK ID (1)
 *      - Encrypted PCK ID (2)
 *      - PCK Certificate (3)
 * @return Status code of the operation. One of:
 *      - STATUS_OK
 *      - STATUS_MISSING_PARAMETERS
 *      - STATUS_UNSUPPORTED_QUOTE_FORMAT
 *      - STATUS_INVALID_QE_CERTIFICATION_DATA_SIZE
 *      - STATUS_UNSUPPORTED_QE_CERTIFICATION_DATA_TYPE
 */
QVL_API Status sgxAttestationGetQECertificationData(
        const uint8_t *quote,
        uint32_t quoteSize,
        uint32_t qeCertificationDataSize,
        uint8_t *qeCertificationData,
        uint16_t *qeCertificationDataType);

/**
 * This function is responsible for verifying if provided PCK Certificate Chain is valid.
 *
 * @param pemCertChain - Null terminated string containing x.509 certificates in PEM format concatenated together:
 *      - Intel SGX Root CA certificate
 *      - Intel SGX PCK Platform or Processor CA certificate
 *      - Intel SGX PCK certificate
 * @param crls - Table with two, null terminated PEM formatted x.509 CRLs. Function will try to access two indexes:
 *      - crls[0] - CRL issued by root CA
 *      - crls[1] - CRL issued by intermediate certificate.
 * @param pemRootCaCertificate - Null terminated Intel SGX Root CA certificate (x.509, self-signed) in PEM format.
 * @return Status code of the operation. One of:
 *      - STATUS_OK
 *      - STATUS_UNSUPPORTED_CERT_FORMAT
 *      - STATUS_SGX_ROOT_CA_MISSING
 *      - STATUS_SGX_ROOT_CA_INVALID
 *      - STATUS_SGX_ROOT_CA_INVALID_EXTENSIONS
 *      - STATUS_SGX_ROOT_CA_INVALID_ISSUER
 *      - STATUS_SGX_INTERMEDIATE_CA_MISSING
 *      - STATUS_SGX_INTERMEDIATE_CA_INVALID
 *      - STATUS_SGX_INTERMEDIATE_CA_INVALID_EXTENSIONS
 *      - STATUS_SGX_INTERMEDIATE_CA_INVALID_ISSUER
 *      - STATUS_SGX_INTERMEDIATE_CA_REVOKED
 *      - STATUS_SGX_PCK_MISSING
 *      - STATUS_SGX_PCK_INVALID
 *      - STATUS_SGX_PCK_INVALID_EXTENSIONS
 *      - STATUS_SGX_PCK_INVALID_ISSUER
 *      - STATUS_SGX_PCK_REVOKED
 *      - STATUS_TRUSTED_ROOT_CA_INVALID
 *      - STATUS_SGX_PCK_CERT_CHAIN_UNTRUSTED
 *      - STATUS_SGX_CRL_UNSUPPORTED_FORMAT
 *      - STATUS_SGX_CRL_UNKNOWN_ISSUER
 *      - STATUS_SGX_CRL_INVALID
 *      - STATUS_SGX_CRL_INVALID_EXTENSIONS
 *      - STATUS_SGX_CRL_INVALID_SIGNATURE
 */
QVL_API Status sgxAttestationVerifyPCKCertificate(const char *pemCertChain, const char *const crls[], const char *pemRootCaCertificate);

/**
 * This function is responsible for verifying TCB Info structure issued by Intel SGX TCB Signing Certificate.
 *
 * @param tcbInfo - TCB Info structure in JSON format signed by Intel SGX TCB Signing Certificate.
 * @param pemCertChain - x.509 TCB Signing Certificate chain (that signed provided TCBInfo) in PEM format concatenated together.
 * @param pemRootCaCrl - x.509 SGX Root CA CRL in PEM format.
 * @param pemRootCaCertificate - Intel SGX Root CA certificate (x.509, self-signed) in PEM format.
 * @return Status code of the operation. One of:
 *      - STATUS_OK
 *      - STATUS_SGX_TCB_INFO_UNSUPPORTED_FORMAT
 *      - STATUS_SGX_TCB_INFO_INVALID
 *      - STATUS_TCB_INFO_INVALID_SIGNATURE
 *      - STATUS_UNSUPPORTED_CERT_FORMAT
 *      - STATUS_SGX_ROOT_CA_MISSING
 *      - STATUS_SGX_ROOT_CA_INVALID
 *      - STATUS_SGX_ROOT_CA_INVALID_EXTENSIONS
 *      - STATUS_SGX_ROOT_CA_INVALID_ISSUER
 *      - STATUS_SGX_TCB_SIGNING_CERT_MISSING
 *      - STATUS_SGX_TCB_SIGNING_CERT_INVALID
 *      - STATUS_SGX_TCB_SIGNING_CERT_INVALID_EXTENSIONS
 *      - STATUS_SGX_TCB_SIGNING_CERT_INVALID_ISSUER
 *      - STATUS_SGX_TCB_SIGNING_CERT_REVOKED
 *      - STATUS_TRUSTED_ROOT_CA_INVALID
 *      - STATUS_SGX_TCB_SIGNING_CERT_CHAIN_UNTRUSTED
 *      - STATUS_SGX_CRL_UNSUPPORTED_FORMAT
 *      - STATUS_SGX_CRL_UNKNOWN_ISSUER
 *      - STATUS_SGX_CRL_INVALID
 *      - STATUS_SGX_CRL_INVALID_EXTENSIONS
 *      - STATUS_SGX_CRL_INVALID_SIGNATURE
 */
QVL_API Status sgxAttestationVerifyTCBInfo(const char *tcbInfo, const char *pemCertChain, const char *pemRootCaCrl, const char *pemRootCaCertificate);

/**
 * This function is responsible for verifying QE Identity structure.
 *
 * @param qeIdentity - QE Identity structure in JSON format signed by Intel SGX TCB Signing Certificate.
 * @param pemCertChain - x.509 TCB Signing Certificate chain (that signed provided QE Identity) in PEM format concatenated together.
 * @param pemRootCaCrl - x.509 SGX Root CA CRL in PEM format.
 * @param pemRootCaCertificate - Intel SGX Root CA certificate (x.509, self-signed) in PEM format.
 * @return Status code of the operation. One of:
 *      - STATUS_OK
 *      - STATUS_SGX_QE_IDENTITY_UNSUPPORTED_FORMAT
 *      - STATUS_SGX_QE_IDENTITY_INVALID
 *      - STATUS_SGX_QE_IDENTITY_INVALID_SIGNATURE
 *      - STATUS_UNSUPPORTED_CERT_FORMAT
 *      - STATUS_SGX_ROOT_CA_MISSING
 *      - STATUS_SGX_ROOT_CA_INVALID
 *      - STATUS_SGX_ROOT_CA_INVALID_EXTENSIONS
 *      - STATUS_SGX_ROOT_CA_INVALID_ISSUER
 *      - STATUS_SGX_TCB_SIGNING_CERT_MISSING
 *      - STATUS_SGX_TCB_SIGNING_CERT_INVALID
 *      - STATUS_SGX_TCB_SIGNING_CERT_INVALID_EXTENSIONS
 *      - STATUS_SGX_TCB_SIGNING_CERT_INVALID_ISSUER
 *      - STATUS_SGX_TCB_SIGNING_CERT_REVOKED
 *      - STATUS_TRUSTED_ROOT_CA_INVALID
 *      - STATUS_SGX_TCB_SIGNING_CERT_CHAIN_UNTRUSTED
 *      - STATUS_SGX_CRL_UNSUPPORTED_FORMAT

 */
QVL_API Status sgxAttestationVerifyQEIdentity(const char *qeIdentity, const char *pemCertChain, const char *pemRootCaCrl, const char *pemRootCaCertificate);

/**
 * This function is responsible for verifying Certificate Revocation Lists issued by one of the CA certificates in
 * PCK Certificate Chain.
 *
 * @param crl - Null terminated, PEM formatted x.509 Certificate Revocation Lists supported by PCK Certificate Chain. One of:
 *      - Intel SGX Root CA CRL
 *      - Intel SGX PCK Platform CRL
 *      - Intel SGX PCK Processor CRL
 * @param pemCACertChain - x.509 CA certificates (that issued provided CRL) in PEM format concatenated together
 * @param pemTrustedRootCaCert - Intel SGX Root CA certificate (x.509, self-signed) in PEM format.
 * @return Status code of the operation. One of:
 *      - STATUS_OK
 *      - STATUS_SGX_CRL_UNSUPPORTED_FORMAT
 *      - STATUS_SGX_CRL_UNKNOWN_ISSUER
 *      - STATUS_SGX_CRL_INVALID
 *      - STATUS_SGX_CRL_INVALID_EXTENSIONS
 *      - STATUS_SGX_CRL_INVALID_SIGNATURE
 *      - STATUS_SGX_CA_CERT_UNSUPPORTED_FORMAT
 *      - STATUS_SGX_CA_CERT_INVALID
 *      - STATUS_TRUSTED_ROOT_CA_UNSUPPORTED_FORMAT
 *      - STATUS_TRUSTED_ROOT_CA_INVALID
 *      - STATUS_SGX_ROOT_CA_UNTRUSTED
 */
QVL_API Status sgxAttestationVerifyPCKRevocationList(const char *crl, const char *pemCACertChain, const char *pemTrustedRootCaCert);

/** @}*/

#endif //SGX_ECDSA_QUOTE_VERIFICATION_H_
};
