// automatically generated by the FlatBuffers compiler, do not modify

package data_map

import (
	flatbuffers "github.com/google/flatbuffers/go"
)

/// simple simili-map type for Flatbuffers
/// map entry
/// maps a key to a value
/// id: string
/// value: data
type MapEntry struct {
	_tab flatbuffers.Table
}

func GetRootAsMapEntry(buf []byte, offset flatbuffers.UOffsetT) *MapEntry {
	n := flatbuffers.GetUOffsetT(buf[offset:])
	x := &MapEntry{}
	x.Init(buf, n+offset)
	return x
}

func (rcv *MapEntry) Init(buf []byte, i flatbuffers.UOffsetT) {
	rcv._tab.Bytes = buf
	rcv._tab.Pos = i
}

func (rcv *MapEntry) Table() flatbuffers.Table {
	return rcv._tab
}

func (rcv *MapEntry) Id() []byte {
	o := flatbuffers.UOffsetT(rcv._tab.Offset(4))
	if o != 0 {
		return rcv._tab.ByteVector(o + rcv._tab.Pos)
	}
	return nil
}

func (rcv *MapEntry) Value(j int) byte {
	o := flatbuffers.UOffsetT(rcv._tab.Offset(6))
	if o != 0 {
		a := rcv._tab.Vector(o)
		return rcv._tab.GetByte(a + flatbuffers.UOffsetT(j*1))
	}
	return 0
}

func (rcv *MapEntry) ValueLength() int {
	o := flatbuffers.UOffsetT(rcv._tab.Offset(6))
	if o != 0 {
		return rcv._tab.VectorLen(o)
	}
	return 0
}

func (rcv *MapEntry) ValueBytes() []byte {
	o := flatbuffers.UOffsetT(rcv._tab.Offset(6))
	if o != 0 {
		return rcv._tab.ByteVector(o + rcv._tab.Pos)
	}
	return nil
}

func MapEntryStart(builder *flatbuffers.Builder) {
	builder.StartObject(2)
}
func MapEntryAddId(builder *flatbuffers.Builder, id flatbuffers.UOffsetT) {
	builder.PrependUOffsetTSlot(0, flatbuffers.UOffsetT(id), 0)
}
func MapEntryAddValue(builder *flatbuffers.Builder, value flatbuffers.UOffsetT) {
	builder.PrependUOffsetTSlot(1, flatbuffers.UOffsetT(value), 0)
}
func MapEntryStartValueVector(builder *flatbuffers.Builder, numElems int) flatbuffers.UOffsetT {
	return builder.StartVector(1, numElems, 1)
}
func MapEntryEnd(builder *flatbuffers.Builder) flatbuffers.UOffsetT {
	return builder.EndObject()
}
