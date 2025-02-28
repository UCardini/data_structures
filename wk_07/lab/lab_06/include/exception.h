#include "dataStructures.h"

class stackOverflow
{
private:
public:
    stackOverflow();
    stackOverflow( stackOverflow&& )                 = default;
    stackOverflow( const stackOverflow& )            = default;
    stackOverflow& operator=( stackOverflow&& )      = default;
    stackOverflow& operator=( const stackOverflow& ) = default;
    ~stackOverflow();
};

class stackUnderflow
{
private:
public:
    stackUnderflow();
    stackUnderflow( stackUnderflow&& )                 = default;
    stackUnderflow( const stackUnderflow& )            = default;
    stackUnderflow& operator=( stackUnderflow&& )      = default;
    stackUnderflow& operator=( const stackUnderflow& ) = default;
    ~stackUnderflow();
};

class queueOverflow
{
private:
public:
    queueOverflow();
    queueOverflow( queueOverflow&& )                 = default;
    queueOverflow( const queueOverflow& )            = default;
    queueOverflow& operator=( queueOverflow&& )      = default;
    queueOverflow& operator=( const queueOverflow& ) = default;
    ~queueOverflow();
};

class queueUnderflow
{
private:
public:
    queueUnderflow();
    queueUnderflow( queueUnderflow&& )                 = default;
    queueUnderflow( const queueUnderflow& )            = default;
    queueUnderflow& operator=( queueUnderflow&& )      = default;
    queueUnderflow& operator=( const queueUnderflow& ) = default;
    ~queueUnderflow();
};
