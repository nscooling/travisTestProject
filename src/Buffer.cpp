// ----------------------------------------------------------------------------------
// Buffer.cpp
// 
// DISCLAIMER:
// Feabhas is furnishing this item "as is". Feabhas does not provide any warranty
// of the item whatsoever, whether express, implied, or statutory, including, but
// not limited to, any warranty of merchantability or fitness for a particular
// purpose or any warranty that the contents of the item will be error-free.
// In no respect shall Feabhas incur any liability for any damages, including, but
// limited to, direct, indirect, special, or consequential damages arising out of,
// resulting from, or any way connected to the use of the item, whether or not
// based upon warranty, contract, tort, or otherwise; whether or not injury was
// sustained by persons or property or otherwise; and whether or not loss was
// sustained from, or arose out of, the results of, the item, or any services that
// may be provided by Feabhas.
// ----------------------------------------------------------------------------------

#include "Buffer.h"

Buffer::Buffer() :
  read(0),
  write(0),
  numItems(0)
{
}


Buffer::Error Buffer::add(const Buffer::Elem_Ty& value)
{
  if (numItems == sz) return FULL;

  buffer[write] = value;
  ++numItems;
  ++write;
  if (write == sz) write = 0;

  return OK;
}


Buffer::Error Buffer::get(Buffer::Elem_Ty& value)
{
  if (numItems == 0) return EMPTY;

  value = buffer[read];
  --numItems;
  ++read;
  if (read == sz) read = 0;

  return OK;
}


bool Buffer::isEmpty() const
{
  return (numItems == 0);
}


