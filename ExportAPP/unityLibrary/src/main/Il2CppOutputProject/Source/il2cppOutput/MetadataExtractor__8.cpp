#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


template <typename T1, typename T2>
struct VirtualActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R, typename T1, typename T2, typename T3>
struct VirtualFuncInvoker3
{
	typedef R (*Func)(void*, T1, T2, T3, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, p3, invokeData.method);
	}
};
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};

// System.Collections.Generic.Dictionary`2<System.Int32,System.Text.Encoding>
struct Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54;
// System.Collections.Generic.Dictionary`2<System.Int32,System.Object>
struct Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907;
// System.Collections.Generic.Dictionary`2<System.Int32,System.String>
struct Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9;
// System.Func`2<MetadataExtractor.Formats.Jpeg.JpegSegment,System.Boolean>
struct Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E;
// System.Func`2<MetadataExtractor.Formats.Jpeg.JpegSegment,MetadataExtractor.Directory>
struct Func_2_t679C7E0EDC405525B5A0DB02A53918AA6DD25D08;
// System.Func`2<System.Object,System.Boolean>
struct Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00;
// System.Func`2<System.Object,System.Object>
struct Func_2_tACBF5A1656250800CE861707354491F0611F6624;
// System.Collections.Generic.ICollection`1<MetadataExtractor.Formats.Jpeg.JpegSegmentType>
struct ICollection_1_tBF925CC395B8DAB668376B0CB3B3B13103884576;
// System.Collections.Generic.IEnumerable`1<MetadataExtractor.Directory>
struct IEnumerable_1_tCB41F55A91F8572D15A3F740ADDC27D7ACC36818;
// System.Collections.Generic.IEnumerable`1<MetadataExtractor.Formats.Jpeg.JpegSegment>
struct IEnumerable_1_t78ECB91E4BCA01CBB34768558EAE515E51C785BE;
// System.Collections.Generic.IEnumerable`1<System.Object>
struct IEnumerable_1_tF95C9E01A913DD50575531C8305932628663D9E9;
// System.Collections.Generic.IEqualityComparer`1<System.Int32>
struct IEqualityComparer_1_tDBFC8496F14612776AF930DBF84AFE7D06D1F0E9;
// System.Collections.Generic.IReadOnlyList`1<MetadataExtractor.Directory>
struct IReadOnlyList_1_t0155EFB6BC5FAD24B44190D3BE8DFA46CB79347A;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.Int32,System.String>
struct KeyCollection_t78693409E5147276425329CB69C1414D43C8CCE5;
// System.Collections.Generic.List`1<MetadataExtractor.Directory>
struct List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0;
// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
// System.Collections.Generic.List`1<System.String>
struct List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD;
// System.Collections.Generic.List`1<MetadataExtractor.Tag>
struct List_1_t70E111480A8CBD0A32DCF0F024DC784B3EF2ED5B;
// MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Adobe.AdobeJpegDirectory>
struct TagDescriptor_1_t79D01947DFE7B33543ECC55186FA0E26055A4102;
// MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Avi.AviDirectory>
struct TagDescriptor_1_t581EFB73E33C37F2BE9E941CD5ECE902A891428E;
// MetadataExtractor.TagDescriptor`1<System.Object>
struct TagDescriptor_1_t54DDB11CF6366D35183686BA442DEBB16FF64390;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,System.String>
struct ValueCollection_tE9183007A5785689F86BDBB22CB72D19AB5E1192;
// System.Collections.Generic.Dictionary`2/Entry<System.Int32,System.String>[]
struct EntryU5BU5D_t8551361338B9BF5705CA61FFE9EA2EDEA1B1EF34;
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
// MetadataExtractor.Directory[]
struct DirectoryU5BU5D_tA8BCAFF2D03278FF6AF1CE0E8482EA0B25CB9BC7;
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
// System.IntPtr[]
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// MetadataExtractor.Formats.Adobe.AdobeJpegDescriptor
struct AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA;
// MetadataExtractor.Formats.Adobe.AdobeJpegDirectory
struct AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0;
// MetadataExtractor.Formats.Adobe.AdobeJpegReader
struct AdobeJpegReader_t56227C3FB644AA11F0432D3331E7C5AB9872FBE5;
// MetadataExtractor.Formats.Avi.AviDescriptor
struct AviDescriptor_t960F270A1DD847552FB983C076B5848D5A0DB623;
// MetadataExtractor.Formats.Avi.AviDirectory
struct AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2;
// MetadataExtractor.Formats.Avi.AviRiffHandler
struct AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5;
// MetadataExtractor.IO.ByteArrayReader
struct ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F;
// System.Globalization.CodePageDataItem
struct CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2;
// System.Text.DecoderFallback
struct DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// MetadataExtractor.Directory
struct Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A;
// System.Text.EncoderFallback
struct EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293;
// System.Text.Encoding
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095;
// MetadataExtractor.Formats.FileSystem.FileMetadataDirectory
struct FileMetadataDirectory_tFC758B6264064AE8FEF472AC8B8C5C5E74C1D647;
// MetadataExtractor.Formats.FileSystem.FileMetadataReader
struct FileMetadataReader_tF9C052702D0220FC039CB536D35F98640B92791B;
// System.IO.FileStream
struct FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8;
// System.Collections.IDictionary
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
// MetadataExtractor.Formats.Riff.IRiffHandler
struct IRiffHandler_t3D222A458D17C27F8EB150E95627F4F39FEEC720;
// MetadataExtractor.ITagDescriptor
struct ITagDescriptor_tD7FEED239710A46795E9521B0F0F06FE0C287F1A;
// MetadataExtractor.IO.IndexedReader
struct IndexedReader_t22E754BF7EB6C22AD3812A7E1E2B44E0555B30C5;
// MetadataExtractor.Formats.Jpeg.JpegSegment
struct JpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// MetadataExtractor.Formats.Riff.RiffReader
struct RiffReader_t4FB59AD8B47193BCE6ECBEC717299EC0CD8C1F6F;
// Microsoft.Win32.SafeHandles.SafeFileHandle
struct SafeFileHandle_t033FA6AAAC65F4BB25F4CBA9A242A58C95CD406E;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
// System.Threading.SemaphoreSlim
struct SemaphoreSlim_t0D5CB5685D9BFA5BF95CEC6E7395490F933E8DB2;
// MetadataExtractor.IO.SequentialByteArrayReader
struct SequentialByteArrayReader_t56E08F41E026F2B557D64F7199F9A5FBFE7D7829;
// MetadataExtractor.IO.SequentialReader
struct SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01;
// MetadataExtractor.IO.SequentialStreamReader
struct SequentialStreamReader_t1D963C5D7C36DFC24FAE963ECEDBA4B82127EDE5;
// System.IO.Stream
struct Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE;
// System.String
struct String_t;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// MetadataExtractor.Formats.Adobe.AdobeJpegReader/<>c
struct U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53;
// System.IO.Stream/ReadWriteTask
struct ReadWriteTask_t0821BF49EE38596C7734E86E1A6A39D769BE2C05;

IL2CPP_EXTERN_C RuntimeClass* AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AviDescriptor_t960F270A1DD847552FB983C076B5848D5A0DB623_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DirectoryExtensions_t2A0E3E30420855CA057298B18B2396625DDF5E1D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* FileMetadataReader_tF9C052702D0220FC039CB536D35F98640B92791B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Func_2_t679C7E0EDC405525B5A0DB02A53918AA6DD25D08_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* JpegSegmentTypeU5BU5D_t84EA1C1277027054474CD7AF7079DB6B06020C4E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RiffReader_t4FB59AD8B47193BCE6ECBEC717299EC0CD8C1F6F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SequentialByteArrayReader_t56E08F41E026F2B557D64F7199F9A5FBFE7D7829_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SequentialStreamReader_t1D963C5D7C36DFC24FAE963ECEDBA4B82127EDE5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral0008402531FBD99F266E5EAFCB7BB9B756EF702D;
IL2CPP_EXTERN_C String_t* _stringLiteral064FE1C639C81D5F3142367FD90FD448C4488741;
IL2CPP_EXTERN_C String_t* _stringLiteral0978FD46E12CEBAC1D88B02D0DAA2E2F3A201C72;
IL2CPP_EXTERN_C String_t* _stringLiteral0BA78D96D07EAF82150E77394E877D66DF74C1EF;
IL2CPP_EXTERN_C String_t* _stringLiteral0ED6B34E76D21901E1C28D2BBF5CB55189434E91;
IL2CPP_EXTERN_C String_t* _stringLiteral1CBED9D36BAFE97D121834BB68CDA8E193A8E56D;
IL2CPP_EXTERN_C String_t* _stringLiteral2126DFC852A96E6C3DA999CD42496F1B088AC913;
IL2CPP_EXTERN_C String_t* _stringLiteral30F39003DB1F504B0EE157F9D8ED6AE9C278239F;
IL2CPP_EXTERN_C String_t* _stringLiteral344E909CD08D994F8FC624350866CAE2DF2D2BD0;
IL2CPP_EXTERN_C String_t* _stringLiteral48ECEE4566B670DF276CFBA62874E0AB6F2E9D7A;
IL2CPP_EXTERN_C String_t* _stringLiteral4A4B98C54B2B1646B779755C6E122D933AD6CBB9;
IL2CPP_EXTERN_C String_t* _stringLiteral65962AB7981D7DED4606F8986A6AA25EAE045B40;
IL2CPP_EXTERN_C String_t* _stringLiteral8FE94193A3EF39943F898714AC9062F7EBD96279;
IL2CPP_EXTERN_C String_t* _stringLiteral92094BBD8DE1A81022C0FCA98F179197BA588E99;
IL2CPP_EXTERN_C String_t* _stringLiteralA00F72EF07EA85C3BAF99CB22C2C280A69C46BC1;
IL2CPP_EXTERN_C String_t* _stringLiteralA39994C06ED3CE0D019E2021E3F684287743F375;
IL2CPP_EXTERN_C String_t* _stringLiteralA8080615DB133763964A575ADBD1FBB06D00D893;
IL2CPP_EXTERN_C String_t* _stringLiteralA8A3DD69001985C64C03CED9DF19EB43748F7283;
IL2CPP_EXTERN_C String_t* _stringLiteralA8B876E75236FD879B6F61E168F508D2FDE6C753;
IL2CPP_EXTERN_C String_t* _stringLiteralAD298E5344B7CC8B91C66A36A7F003ABA7B7538B;
IL2CPP_EXTERN_C String_t* _stringLiteralB0A138833DBD8A7FE850184B283B6396492468D0;
IL2CPP_EXTERN_C String_t* _stringLiteralB467A7760289D7B8EFDBF49D0ED022BFDA84240E;
IL2CPP_EXTERN_C String_t* _stringLiteralBF51FA64951F7449D906BFEB40DDC7E3B1F44CBF;
IL2CPP_EXTERN_C String_t* _stringLiteralC124374D124AF1895C0D2EAF802B3DB47E24A2BA;
IL2CPP_EXTERN_C String_t* _stringLiteralE3643A741AC27679DCBEE196E29D8FDAACE03A2D;
IL2CPP_EXTERN_C String_t* _stringLiteralE738E8A8D805659811C98E0A2B2E7A9C24ACF9D1;
IL2CPP_EXTERN_C String_t* _stringLiteralEB39CBBCF7B7F393A23C0D8D902221EDE9A739DA;
IL2CPP_EXTERN_C String_t* _stringLiteralEB408DDC4FA484E6BEFDF5954E56A2198C7A9FAB;
IL2CPP_EXTERN_C String_t* _stringLiteralF1F4EE83F4EF40DB53192A2B50D97E241E77A4EB;
IL2CPP_EXTERN_C String_t* _stringLiteralF37C9765467D4EA1B14DD2BA48881A211A3B8C06;
IL2CPP_EXTERN_C String_t* _stringLiteralF4C8E44AADA30D965F3A1F9F20D08293CC5C8ABC;
IL2CPP_EXTERN_C String_t* _stringLiteralF657A368792D4A12C0CB5C93FDF095A8F3C96653;
IL2CPP_EXTERN_C String_t* _stringLiteralFA547AA5C8BB8C7AA96008C6E522BDDA8C5207D5;
IL2CPP_EXTERN_C String_t* _stringLiteralFBA5ADEA08A8958332ED2BC70EC48D3A8987BAED;
IL2CPP_EXTERN_C String_t* _stringLiteralFDEA9EABBBF0EEFF81C2958C4C87A3E791E08FEA;
IL2CPP_EXTERN_C const RuntimeMethod* AdobeJpegReader_U3CReadJpegSegmentsU3Eb__4_1_m9B26E13582B739ECBBEAD4CBF6DF57EAE2C4C530_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_mC854597C0C338BBA12EE451456D8658DF6D01BD4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_Select_TisJpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF_TisDirectory_t3179A156C81D90563D22A0D009C0821CE27FA51A_m4DC39D0F277FD093C793D8677DAF1293E6C334C8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_Where_TisJpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF_m0B083B7D77A38F867CF69AFB17AB8E091FEA8902_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_AddRange_mA89FE5F3140BE378BAB28377FAB1EC903A27BA26_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m8C01AC4C40198210118E5E169A4FA596142917A6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m6929C72C345340E3A9577A6F480A8CD784A1DBBB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TagDescriptor_1_GetDescription_m2A08293E7212E61FB0ED1942A5196EAED8678E3F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TagDescriptor_1_GetDescription_m8B50EB473A93AAFE67E71A7A68C7EEB60019BB7E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TagDescriptor_1_GetIndexedDescription_m3C183A03543A77AA047617C6C238F92C8A939D83_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TagDescriptor_1__ctor_m16606A064012009FF0396AC5D50BC57EBF9FC001_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TagDescriptor_1__ctor_m750C1E77A6F3FD3BEA349A0AE3CEF90B1E9E0038_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TagDescriptor_1_get_Directory_m8A529F98C29B4780346A184D79CAF1661EED33A9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TagDescriptor_1_get_Directory_mA075B82F615F061F332E7840C307691A66C87329_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ec_U3CReadJpegSegmentsU3Eb__4_0_m7DDEF62C7E5DFEA9CB46063AF916624971B9644F_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct JpegSegmentTypeU5BU5D_t84EA1C1277027054474CD7AF7079DB6B06020C4E;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Collections.Generic.Dictionary`2<System.Int32,System.String>
struct Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t8551361338B9BF5705CA61FFE9EA2EDEA1B1EF34* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_t78693409E5147276425329CB69C1414D43C8CCE5* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_tE9183007A5785689F86BDBB22CB72D19AB5E1192* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.List`1<MetadataExtractor.Directory>
struct List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	DirectoryU5BU5D_tA8BCAFF2D03278FF6AF1CE0E8482EA0B25CB9BC7* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Adobe.AdobeJpegDirectory>
struct TagDescriptor_1_t79D01947DFE7B33543ECC55186FA0E26055A4102  : public RuntimeObject
{
	// T MetadataExtractor.TagDescriptor`1::<Directory>k__BackingField
	AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* ___U3CDirectoryU3Ek__BackingField_0;
};

// MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Avi.AviDirectory>
struct TagDescriptor_1_t581EFB73E33C37F2BE9E941CD5ECE902A891428E  : public RuntimeObject
{
	// T MetadataExtractor.TagDescriptor`1::<Directory>k__BackingField
	AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* ___U3CDirectoryU3Ek__BackingField_0;
};

// MetadataExtractor.TagDescriptor`1<System.Object>
struct TagDescriptor_1_t54DDB11CF6366D35183686BA442DEBB16FF64390  : public RuntimeObject
{
	// T MetadataExtractor.TagDescriptor`1::<Directory>k__BackingField
	RuntimeObject* ___U3CDirectoryU3Ek__BackingField_0;
};

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_t3B1E41E8F8C7A7227E055A45F0C5075A8C2526F9  : public RuntimeObject
{
};

// MetadataExtractor.Formats.Adobe.AdobeJpegReader
struct AdobeJpegReader_t56227C3FB644AA11F0432D3331E7C5AB9872FBE5  : public RuntimeObject
{
	// System.Collections.Generic.ICollection`1<MetadataExtractor.Formats.Jpeg.JpegSegmentType> MetadataExtractor.Formats.Adobe.AdobeJpegReader::<MetadataExtractor.Formats.Jpeg.IJpegSegmentMetadataReader.SegmentTypes>k__BackingField
	RuntimeObject* ___U3CMetadataExtractor_Formats_Jpeg_IJpegSegmentMetadataReader_SegmentTypesU3Ek__BackingField_1;
};

// MetadataExtractor.Formats.Avi.AviMetadataReader
struct AviMetadataReader_tD66DE86F01DCBC518C84551C64D348CCDEFFCC3A  : public RuntimeObject
{
};

// MetadataExtractor.Formats.Avi.AviRiffHandler
struct AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5  : public RuntimeObject
{
	// System.Collections.Generic.List`1<MetadataExtractor.Directory> MetadataExtractor.Formats.Avi.AviRiffHandler::_directories
	List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* ____directories_0;
	// MetadataExtractor.Formats.Avi.AviDirectory MetadataExtractor.Formats.Avi.AviRiffHandler::_directory
	AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* ____directory_1;
};

// MetadataExtractor.Directory
struct Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A  : public RuntimeObject
{
	// System.Collections.Generic.Dictionary`2<System.Int32,System.String> MetadataExtractor.Directory::_tagNameMap
	Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* ____tagNameMap_1;
	// System.Collections.Generic.Dictionary`2<System.Int32,System.Object> MetadataExtractor.Directory::_tagMap
	Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* ____tagMap_2;
	// System.Collections.Generic.List`1<MetadataExtractor.Tag> MetadataExtractor.Directory::_definedTagList
	List_1_t70E111480A8CBD0A32DCF0F024DC784B3EF2ED5B* ____definedTagList_3;
	// System.Collections.Generic.List`1<System.String> MetadataExtractor.Directory::_errorList
	List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* ____errorList_4;
	// MetadataExtractor.ITagDescriptor MetadataExtractor.Directory::_descriptor
	RuntimeObject* ____descriptor_5;
	// MetadataExtractor.Directory MetadataExtractor.Directory::<Parent>k__BackingField
	Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A* ___U3CParentU3Ek__BackingField_6;
};

// System.Text.Encoding
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095  : public RuntimeObject
{
	// System.Int32 System.Text.Encoding::m_codePage
	int32_t ___m_codePage_9;
	// System.Globalization.CodePageDataItem System.Text.Encoding::dataItem
	CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2* ___dataItem_10;
	// System.Boolean System.Text.Encoding::m_deserializedFromEverett
	bool ___m_deserializedFromEverett_11;
	// System.Boolean System.Text.Encoding::m_isReadOnly
	bool ___m_isReadOnly_12;
	// System.Text.EncoderFallback System.Text.Encoding::encoderFallback
	EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293* ___encoderFallback_13;
	// System.Text.DecoderFallback System.Text.Encoding::decoderFallback
	DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90* ___decoderFallback_14;
};

// MetadataExtractor.Formats.FileSystem.FileMetadataReader
struct FileMetadataReader_tF9C052702D0220FC039CB536D35F98640B92791B  : public RuntimeObject
{
};

// MetadataExtractor.IO.IndexedReader
struct IndexedReader_t22E754BF7EB6C22AD3812A7E1E2B44E0555B30C5  : public RuntimeObject
{
	// System.Boolean MetadataExtractor.IO.IndexedReader::<IsMotorolaByteOrder>k__BackingField
	bool ___U3CIsMotorolaByteOrderU3Ek__BackingField_0;
};

// MetadataExtractor.Formats.Jpeg.JpegSegment
struct JpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF  : public RuntimeObject
{
	// MetadataExtractor.Formats.Jpeg.JpegSegmentType MetadataExtractor.Formats.Jpeg.JpegSegment::<Type>k__BackingField
	uint8_t ___U3CTypeU3Ek__BackingField_0;
	// System.Byte[] MetadataExtractor.Formats.Jpeg.JpegSegment::<Bytes>k__BackingField
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___U3CBytesU3Ek__BackingField_1;
	// System.Int64 MetadataExtractor.Formats.Jpeg.JpegSegment::<Offset>k__BackingField
	int64_t ___U3COffsetU3Ek__BackingField_2;
};

// System.MarshalByRefObject
struct MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE  : public RuntimeObject
{
	// System.Object System.MarshalByRefObject::_identity
	RuntimeObject* ____identity_0;
};
// Native definition for P/Invoke marshalling of System.MarshalByRefObject
struct MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE_marshaled_pinvoke
{
	Il2CppIUnknown* ____identity_0;
};
// Native definition for COM marshalling of System.MarshalByRefObject
struct MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE_marshaled_com
{
	Il2CppIUnknown* ____identity_0;
};

// MetadataExtractor.Formats.Riff.RiffReader
struct RiffReader_t4FB59AD8B47193BCE6ECBEC717299EC0CD8C1F6F  : public RuntimeObject
{
};

// MetadataExtractor.IO.SequentialReader
struct SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01  : public RuntimeObject
{
	// System.Boolean MetadataExtractor.IO.SequentialReader::<IsMotorolaByteOrder>k__BackingField
	bool ___U3CIsMotorolaByteOrderU3Ek__BackingField_0;
};

// System.String
struct String_t  : public RuntimeObject
{
	// System.Int32 System.String::_stringLength
	int32_t ____stringLength_4;
	// System.Char System.String::_firstChar
	Il2CppChar ____firstChar_5;
};

// System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};

// MetadataExtractor.Formats.Adobe.AdobeJpegReader/<>c
struct U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53  : public RuntimeObject
{
};

// MetadataExtractor.Formats.Adobe.AdobeJpegDescriptor
struct AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA  : public TagDescriptor_1_t79D01947DFE7B33543ECC55186FA0E26055A4102
{
};

// MetadataExtractor.Formats.Adobe.AdobeJpegDirectory
struct AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0  : public Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A
{
};

// MetadataExtractor.Formats.Avi.AviDescriptor
struct AviDescriptor_t960F270A1DD847552FB983C076B5848D5A0DB623  : public TagDescriptor_1_t581EFB73E33C37F2BE9E941CD5ECE902A891428E
{
};

// MetadataExtractor.Formats.Avi.AviDirectory
struct AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2  : public Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A
{
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
};

// System.Byte
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	// System.Byte System.Byte::m_value
	uint8_t ___m_value_0;
};

// MetadataExtractor.IO.ByteArrayReader
struct ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F  : public IndexedReader_t22E754BF7EB6C22AD3812A7E1E2B44E0555B30C5
{
	// System.Byte[] MetadataExtractor.IO.ByteArrayReader::_buffer
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ____buffer_1;
	// System.Int32 MetadataExtractor.IO.ByteArrayReader::_baseOffset
	int32_t ____baseOffset_2;
};

// System.DateTime
struct DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D 
{
	// System.UInt64 System.DateTime::_dateData
	uint64_t ____dateData_46;
};

// System.Double
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	// System.Double System.Double::m_value
	double ___m_value_0;
};

// System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
// Native definition for P/Invoke marshalling of System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};

// MetadataExtractor.Formats.FileSystem.FileMetadataDirectory
struct FileMetadataDirectory_tFC758B6264064AE8FEF472AC8B8C5C5E74C1D647  : public Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A
{
};

// System.Int32
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;
};

// System.Int64
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	// System.Int64 System.Int64::m_value
	int64_t ___m_value_0;
};

// System.IntPtr
struct IntPtr_t 
{
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;
};

// System.SByte
struct SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5 
{
	// System.SByte System.SByte::m_value
	int8_t ___m_value_0;
};

// MetadataExtractor.IO.SequentialByteArrayReader
struct SequentialByteArrayReader_t56E08F41E026F2B557D64F7199F9A5FBFE7D7829  : public SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01
{
	// System.Byte[] MetadataExtractor.IO.SequentialByteArrayReader::_bytes
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ____bytes_1;
	// System.Int32 MetadataExtractor.IO.SequentialByteArrayReader::_index
	int32_t ____index_2;
};

// MetadataExtractor.IO.SequentialStreamReader
struct SequentialStreamReader_t1D963C5D7C36DFC24FAE963ECEDBA4B82127EDE5  : public SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01
{
	// System.IO.Stream MetadataExtractor.IO.SequentialStreamReader::_stream
	Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ____stream_1;
};

// System.Single
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	// System.Single System.Single::m_value
	float ___m_value_0;
};

// System.IO.Stream
struct Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE  : public MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE
{
	// System.IO.Stream/ReadWriteTask System.IO.Stream::_activeReadWriteTask
	ReadWriteTask_t0821BF49EE38596C7734E86E1A6A39D769BE2C05* ____activeReadWriteTask_2;
	// System.Threading.SemaphoreSlim System.IO.Stream::_asyncActiveSemaphore
	SemaphoreSlim_t0D5CB5685D9BFA5BF95CEC6E7395490F933E8DB2* ____asyncActiveSemaphore_3;
};

// System.TimeSpan
struct TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A 
{
	// System.Int64 System.TimeSpan::_ticks
	int64_t ____ticks_22;
};

// System.UInt16
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	// System.UInt16 System.UInt16::m_value
	uint16_t ___m_value_0;
};

// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=10
struct __StaticArrayInitTypeSizeU3D10_tD5708E0C2089684C88E6C6C068D295A1303EB599 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D10_tD5708E0C2089684C88E6C6C068D295A1303EB599__padding[10];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=12
struct __StaticArrayInitTypeSizeU3D12_t0EB0A53E273C10A8102B5E9421C708E4841EE954 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D12_t0EB0A53E273C10A8102B5E9421C708E4841EE954__padding[12];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=16
struct __StaticArrayInitTypeSizeU3D16_tFD48ABE478067A6019B122247231BEE7968AB987 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D16_tFD48ABE478067A6019B122247231BEE7968AB987__padding[16];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=162
struct __StaticArrayInitTypeSizeU3D162_t6F0961F6F669B44EFDD817D7FCC2F24E0F04F3FB 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D162_t6F0961F6F669B44EFDD817D7FCC2F24E0F04F3FB__padding[162];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=168
struct __StaticArrayInitTypeSizeU3D168_t7A9FAF6CC4CC640A8C397513B6B90C00A3FCDA12 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D168_t7A9FAF6CC4CC640A8C397513B6B90C00A3FCDA12__padding[168];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=20
struct __StaticArrayInitTypeSizeU3D20_tD1D8ABC420CE4D5B63B50F330D2AEF9578FDE4BF 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D20_tD1D8ABC420CE4D5B63B50F330D2AEF9578FDE4BF__padding[20];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24
struct __StaticArrayInitTypeSizeU3D24_t3DE2BE004C03D1444F354A190F91998F8B682160 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D24_t3DE2BE004C03D1444F354A190F91998F8B682160__padding[24];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=3
struct __StaticArrayInitTypeSizeU3D3_t8CDE0F065D15084A19ED674EFA21A43C5C8B65A5 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D3_t8CDE0F065D15084A19ED674EFA21A43C5C8B65A5__padding[3];
	};
};

// System.Delegate
struct Delegate_t  : public RuntimeObject
{
	// System.IntPtr System.Delegate::method_ptr
	intptr_t ___method_ptr_0;
	// System.IntPtr System.Delegate::invoke_impl
	intptr_t ___invoke_impl_1;
	// System.Object System.Delegate::m_target
	RuntimeObject* ___m_target_2;
	// System.IntPtr System.Delegate::method
	intptr_t ___method_3;
	// System.IntPtr System.Delegate::delegate_trampoline
	intptr_t ___delegate_trampoline_4;
	// System.IntPtr System.Delegate::extra_arg
	intptr_t ___extra_arg_5;
	// System.IntPtr System.Delegate::method_code
	intptr_t ___method_code_6;
	// System.IntPtr System.Delegate::interp_method
	intptr_t ___interp_method_7;
	// System.IntPtr System.Delegate::interp_invoke_impl
	intptr_t ___interp_invoke_impl_8;
	// System.Reflection.MethodInfo System.Delegate::method_info
	MethodInfo_t* ___method_info_9;
	// System.Reflection.MethodInfo System.Delegate::original_method_info
	MethodInfo_t* ___original_method_info_10;
	// System.DelegateData System.Delegate::data
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	// System.Boolean System.Delegate::method_is_virtual
	bool ___method_is_virtual_12;
};
// Native definition for P/Invoke marshalling of System.Delegate
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};
// Native definition for COM marshalling of System.Delegate
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};

// System.Exception
struct Exception_t  : public RuntimeObject
{
	// System.String System.Exception::_className
	String_t* ____className_1;
	// System.String System.Exception::_message
	String_t* ____message_2;
	// System.Collections.IDictionary System.Exception::_data
	RuntimeObject* ____data_3;
	// System.Exception System.Exception::_innerException
	Exception_t* ____innerException_4;
	// System.String System.Exception::_helpURL
	String_t* ____helpURL_5;
	// System.Object System.Exception::_stackTrace
	RuntimeObject* ____stackTrace_6;
	// System.String System.Exception::_stackTraceString
	String_t* ____stackTraceString_7;
	// System.String System.Exception::_remoteStackTraceString
	String_t* ____remoteStackTraceString_8;
	// System.Int32 System.Exception::_remoteStackIndex
	int32_t ____remoteStackIndex_9;
	// System.Object System.Exception::_dynamicMethods
	RuntimeObject* ____dynamicMethods_10;
	// System.Int32 System.Exception::_HResult
	int32_t ____HResult_11;
	// System.String System.Exception::_source
	String_t* ____source_12;
	// System.Runtime.Serialization.SafeSerializationManager System.Exception::_safeSerializationManager
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	// System.Diagnostics.StackTrace[] System.Exception::captured_traces
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	// System.IntPtr[] System.Exception::native_trace_ips
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips_15;
	// System.Int32 System.Exception::caught_in_unmanaged
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for P/Invoke marshalling of System.Exception
struct Exception_t_marshaled_pinvoke
{
	char* ____className_1;
	char* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_pinvoke* ____innerException_4;
	char* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	char* ____stackTraceString_7;
	char* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	char* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for COM marshalling of System.Exception
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className_1;
	Il2CppChar* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_com* ____innerException_4;
	Il2CppChar* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	Il2CppChar* ____stackTraceString_7;
	Il2CppChar* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	Il2CppChar* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};

// System.IO.FileStream
struct FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8  : public Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE
{
	// System.Byte[] System.IO.FileStream::buf
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___buf_6;
	// System.String System.IO.FileStream::name
	String_t* ___name_7;
	// Microsoft.Win32.SafeHandles.SafeFileHandle System.IO.FileStream::safeHandle
	SafeFileHandle_t033FA6AAAC65F4BB25F4CBA9A242A58C95CD406E* ___safeHandle_8;
	// System.Boolean System.IO.FileStream::isExposed
	bool ___isExposed_9;
	// System.Int64 System.IO.FileStream::append_startpos
	int64_t ___append_startpos_10;
	// System.IO.FileAccess System.IO.FileStream::access
	int32_t ___access_11;
	// System.Boolean System.IO.FileStream::owner
	bool ___owner_12;
	// System.Boolean System.IO.FileStream::async
	bool ___async_13;
	// System.Boolean System.IO.FileStream::canseek
	bool ___canseek_14;
	// System.Boolean System.IO.FileStream::anonymous
	bool ___anonymous_15;
	// System.Boolean System.IO.FileStream::buf_dirty
	bool ___buf_dirty_16;
	// System.Int32 System.IO.FileStream::buf_size
	int32_t ___buf_size_17;
	// System.Int32 System.IO.FileStream::buf_length
	int32_t ___buf_length_18;
	// System.Int32 System.IO.FileStream::buf_offset
	int32_t ___buf_offset_19;
	// System.Int64 System.IO.FileStream::buf_start
	int64_t ___buf_start_20;
};

// MetadataExtractor.Formats.Jpeg.JpegSegmentType
struct JpegSegmentType_tEA661740CFADBAC7C39D55AF591EBD616A98F59E 
{
	// System.Byte MetadataExtractor.Formats.Jpeg.JpegSegmentType::value__
	uint8_t ___value___2;
};

// System.MulticastDelegate
struct MulticastDelegate_t  : public Delegate_t
{
	// System.Delegate[] System.MulticastDelegate::delegates
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates_13;
};
// Native definition for P/Invoke marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates_13;
};
// Native definition for COM marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates_13;
};

// System.SystemException
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};

// System.Func`2<MetadataExtractor.Formats.Jpeg.JpegSegment,System.Boolean>
struct Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E  : public MulticastDelegate_t
{
};

// System.Func`2<MetadataExtractor.Formats.Jpeg.JpegSegment,MetadataExtractor.Directory>
struct Func_2_t679C7E0EDC405525B5A0DB02A53918AA6DD25D08  : public MulticastDelegate_t
{
};

// System.IO.IOException
struct IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};

// System.Collections.Generic.Dictionary`2<System.Int32,System.String>

// System.Collections.Generic.Dictionary`2<System.Int32,System.String>

// System.Collections.Generic.List`1<MetadataExtractor.Directory>
struct List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	DirectoryU5BU5D_tA8BCAFF2D03278FF6AF1CE0E8482EA0B25CB9BC7* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<MetadataExtractor.Directory>

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Object>

// MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Adobe.AdobeJpegDirectory>

// MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Adobe.AdobeJpegDirectory>

// MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Avi.AviDirectory>

// MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Avi.AviDirectory>

// MetadataExtractor.TagDescriptor`1<System.Object>

// MetadataExtractor.TagDescriptor`1<System.Object>

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_t3B1E41E8F8C7A7227E055A45F0C5075A8C2526F9_StaticFields
{
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=16 <PrivateImplementationDetails>::02A3E298F1533F62558C58E4C70EDCAB9AF5A50D62D925FD5390942020FB0FB8
	__StaticArrayInitTypeSizeU3D16_tFD48ABE478067A6019B122247231BEE7968AB987 ___02A3E298F1533F62558C58E4C70EDCAB9AF5A50D62D925FD5390942020FB0FB8_0;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=16 <PrivateImplementationDetails>::02E0A00BDDA52072D9DC2C8187552AC3C678308B6D642E041C743F8E682EDA8A
	__StaticArrayInitTypeSizeU3D16_tFD48ABE478067A6019B122247231BEE7968AB987 ___02E0A00BDDA52072D9DC2C8187552AC3C678308B6D642E041C743F8E682EDA8A_1;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=3 <PrivateImplementationDetails>::15025191691E087C4FA23736533D3C68A6C5847F911C02948445D03C053F554C
	__StaticArrayInitTypeSizeU3D3_t8CDE0F065D15084A19ED674EFA21A43C5C8B65A5 ___15025191691E087C4FA23736533D3C68A6C5847F911C02948445D03C053F554C_2;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=10 <PrivateImplementationDetails>::18B78ED921EFBC248E125A074F1C4BC321B53CBC5366F75CE13171ED64A0256D
	__StaticArrayInitTypeSizeU3D10_tD5708E0C2089684C88E6C6C068D295A1303EB599 ___18B78ED921EFBC248E125A074F1C4BC321B53CBC5366F75CE13171ED64A0256D_3;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24 <PrivateImplementationDetails>::2976F3EAEEEECB76A8C40649FC5C21A3BFF622E44D1F0B4CAF7211CA09BDEDF4
	__StaticArrayInitTypeSizeU3D24_t3DE2BE004C03D1444F354A190F91998F8B682160 ___2976F3EAEEEECB76A8C40649FC5C21A3BFF622E44D1F0B4CAF7211CA09BDEDF4_4;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=168 <PrivateImplementationDetails>::308300AC88FEF9704F00A6F622B46C9D40298CC64DF2913EAD17444AA5D14DB1
	__StaticArrayInitTypeSizeU3D168_t7A9FAF6CC4CC640A8C397513B6B90C00A3FCDA12 ___308300AC88FEF9704F00A6F622B46C9D40298CC64DF2913EAD17444AA5D14DB1_5;
	// System.Int64 <PrivateImplementationDetails>::3505B8A2248AC03FE41ACADF8F29294572BBADEE1DD2E1A45D025766681C012C
	int64_t ___3505B8A2248AC03FE41ACADF8F29294572BBADEE1DD2E1A45D025766681C012C_6;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=20 <PrivateImplementationDetails>::3EFA7BDA4628DB6DC08E60D432C81A7BD93CC430407FF4E374DA01BEACE5114A
	__StaticArrayInitTypeSizeU3D20_tD1D8ABC420CE4D5B63B50F330D2AEF9578FDE4BF ___3EFA7BDA4628DB6DC08E60D432C81A7BD93CC430407FF4E374DA01BEACE5114A_7;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=16 <PrivateImplementationDetails>::42183E5ADFB18A57973908BE5A4B787B3F64F97CEB3ACAF48CF1158D21B71C9A
	__StaticArrayInitTypeSizeU3D16_tFD48ABE478067A6019B122247231BEE7968AB987 ___42183E5ADFB18A57973908BE5A4B787B3F64F97CEB3ACAF48CF1158D21B71C9A_8;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=162 <PrivateImplementationDetails>::4969C87C7F60DA437B055A7F1A923C48879FD1EFD0D8DF8704C30C1EC1ED4DAE
	__StaticArrayInitTypeSizeU3D162_t6F0961F6F669B44EFDD817D7FCC2F24E0F04F3FB ___4969C87C7F60DA437B055A7F1A923C48879FD1EFD0D8DF8704C30C1EC1ED4DAE_9;
	// System.Int64 <PrivateImplementationDetails>::4C4B6A3BE1314AB86138BEF4314DDE022E600960D8689A2C8F8631802D20DAB6
	int64_t ___4C4B6A3BE1314AB86138BEF4314DDE022E600960D8689A2C8F8631802D20DAB6_10;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=162 <PrivateImplementationDetails>::4D4026641BCA83EAF03A2262F52E074C93B8A14B3E80EC083B7274777B956687
	__StaticArrayInitTypeSizeU3D162_t6F0961F6F669B44EFDD817D7FCC2F24E0F04F3FB ___4D4026641BCA83EAF03A2262F52E074C93B8A14B3E80EC083B7274777B956687_11;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=16 <PrivateImplementationDetails>::6550A2482936741A5153C557043C37056F4E42671EED2FB8C8123A76AEB48B28
	__StaticArrayInitTypeSizeU3D16_tFD48ABE478067A6019B122247231BEE7968AB987 ___6550A2482936741A5153C557043C37056F4E42671EED2FB8C8123A76AEB48B28_12;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=3 <PrivateImplementationDetails>::662F83433EB54AA914618B725AE8276ADABA77C9D14F07E239CF2E88071062C4
	__StaticArrayInitTypeSizeU3D3_t8CDE0F065D15084A19ED674EFA21A43C5C8B65A5 ___662F83433EB54AA914618B725AE8276ADABA77C9D14F07E239CF2E88071062C4_13;
	// System.Int64 <PrivateImplementationDetails>::86C313C97583EF5034708D46A88721BAA0AB3869D4C9733F872720C865E75B31
	int64_t ___86C313C97583EF5034708D46A88721BAA0AB3869D4C9733F872720C865E75B31_14;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=16 <PrivateImplementationDetails>::8917351AA71A08FE9520726A470E77DEC61F045DF83DD22C4A08746F3ADFC05E
	__StaticArrayInitTypeSizeU3D16_tFD48ABE478067A6019B122247231BEE7968AB987 ___8917351AA71A08FE9520726A470E77DEC61F045DF83DD22C4A08746F3ADFC05E_15;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=16 <PrivateImplementationDetails>::AC0E12E2A1868C7D94FD2D937C6ABCD6E5935C874A5C46E7642BCF22E89C40A9
	__StaticArrayInitTypeSizeU3D16_tFD48ABE478067A6019B122247231BEE7968AB987 ___AC0E12E2A1868C7D94FD2D937C6ABCD6E5935C874A5C46E7642BCF22E89C40A9_16;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=20 <PrivateImplementationDetails>::CD82F8CBBAE0E08AD97DD079F1608973F971CABDB23C2762E7366147665A9CFD
	__StaticArrayInitTypeSizeU3D20_tD1D8ABC420CE4D5B63B50F330D2AEF9578FDE4BF ___CD82F8CBBAE0E08AD97DD079F1608973F971CABDB23C2762E7366147665A9CFD_17;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=3 <PrivateImplementationDetails>::CE5FAB6396A269D166BE9A211ABD0FFA06762DC3EC0A302BA9EF386774CA07FE
	__StaticArrayInitTypeSizeU3D3_t8CDE0F065D15084A19ED674EFA21A43C5C8B65A5 ___CE5FAB6396A269D166BE9A211ABD0FFA06762DC3EC0A302BA9EF386774CA07FE_18;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=16 <PrivateImplementationDetails>::F1AF7795290FC7E50641AF6D96CD32D2EA983E6200F9D2E5FD2B2A12BFBB9387
	__StaticArrayInitTypeSizeU3D16_tFD48ABE478067A6019B122247231BEE7968AB987 ___F1AF7795290FC7E50641AF6D96CD32D2EA983E6200F9D2E5FD2B2A12BFBB9387_19;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=16 <PrivateImplementationDetails>::F334FB4E9E85455ACD44CACB404E2173325557B8BDD32C6316F43B09DA86A4F5
	__StaticArrayInitTypeSizeU3D16_tFD48ABE478067A6019B122247231BEE7968AB987 ___F334FB4E9E85455ACD44CACB404E2173325557B8BDD32C6316F43B09DA86A4F5_20;
	// System.Int32 <PrivateImplementationDetails>::F99A8732B9A35AF4A4129628D31AC84C44F05F6509E8E516BF1C2802DE701B7F
	int32_t ___F99A8732B9A35AF4A4129628D31AC84C44F05F6509E8E516BF1C2802DE701B7F_21;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=12 <PrivateImplementationDetails>::FFF3A9BCDD37363D703C1C4F9512533686157868F0D4F16A0F02D0F1DA24F9A2
	__StaticArrayInitTypeSizeU3D12_t0EB0A53E273C10A8102B5E9421C708E4841EE954 ___FFF3A9BCDD37363D703C1C4F9512533686157868F0D4F16A0F02D0F1DA24F9A2_22;
};

// <PrivateImplementationDetails>

// MetadataExtractor.Formats.Adobe.AdobeJpegReader

// MetadataExtractor.Formats.Adobe.AdobeJpegReader

// MetadataExtractor.Formats.Avi.AviMetadataReader

// MetadataExtractor.Formats.Avi.AviMetadataReader

// MetadataExtractor.Formats.Avi.AviRiffHandler

// MetadataExtractor.Formats.Avi.AviRiffHandler

// MetadataExtractor.Directory
struct Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A_StaticFields
{
	// System.Collections.Generic.IReadOnlyList`1<MetadataExtractor.Directory> MetadataExtractor.Directory::EmptyList
	RuntimeObject* ___EmptyList_0;
};

// MetadataExtractor.Directory

// System.Text.Encoding
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095_StaticFields
{
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::defaultEncoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___defaultEncoding_0;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::unicodeEncoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___unicodeEncoding_1;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::bigEndianUnicode
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___bigEndianUnicode_2;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::utf7Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf7Encoding_3;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::utf8Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf8Encoding_4;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::utf32Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf32Encoding_5;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::asciiEncoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___asciiEncoding_6;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::latin1Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___latin1Encoding_7;
	// System.Collections.Generic.Dictionary`2<System.Int32,System.Text.Encoding> modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::encodings
	Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54* ___encodings_8;
	// System.Object System.Text.Encoding::s_InternalSyncObject
	RuntimeObject* ___s_InternalSyncObject_15;
};

// System.Text.Encoding

// MetadataExtractor.Formats.FileSystem.FileMetadataReader

// MetadataExtractor.Formats.FileSystem.FileMetadataReader

// MetadataExtractor.IO.IndexedReader

// MetadataExtractor.IO.IndexedReader

// MetadataExtractor.Formats.Jpeg.JpegSegment

// MetadataExtractor.Formats.Jpeg.JpegSegment

// MetadataExtractor.Formats.Riff.RiffReader

// MetadataExtractor.Formats.Riff.RiffReader

// MetadataExtractor.IO.SequentialReader

// MetadataExtractor.IO.SequentialReader

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// MetadataExtractor.Formats.Adobe.AdobeJpegReader/<>c
struct U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_StaticFields
{
	// MetadataExtractor.Formats.Adobe.AdobeJpegReader/<>c MetadataExtractor.Formats.Adobe.AdobeJpegReader/<>c::<>9
	U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53* ___U3CU3E9_0;
	// System.Func`2<MetadataExtractor.Formats.Jpeg.JpegSegment,System.Boolean> MetadataExtractor.Formats.Adobe.AdobeJpegReader/<>c::<>9__4_0
	Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E* ___U3CU3E9__4_0_1;
};

// MetadataExtractor.Formats.Adobe.AdobeJpegReader/<>c

// MetadataExtractor.Formats.Adobe.AdobeJpegDescriptor

// MetadataExtractor.Formats.Adobe.AdobeJpegDescriptor

// MetadataExtractor.Formats.Adobe.AdobeJpegDirectory
struct AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_StaticFields
{
	// System.Collections.Generic.Dictionary`2<System.Int32,System.String> MetadataExtractor.Formats.Adobe.AdobeJpegDirectory::_tagNameMap
	Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* ____tagNameMap_11;
};

// MetadataExtractor.Formats.Adobe.AdobeJpegDirectory

// MetadataExtractor.Formats.Avi.AviDescriptor

// MetadataExtractor.Formats.Avi.AviDescriptor

// MetadataExtractor.Formats.Avi.AviDirectory
struct AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_StaticFields
{
	// System.Collections.Generic.Dictionary`2<System.Int32,System.String> MetadataExtractor.Formats.Avi.AviDirectory::_tagNameMap
	Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* ____tagNameMap_16;
};

// MetadataExtractor.Formats.Avi.AviDirectory

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Boolean

// System.Byte

// System.Byte

// MetadataExtractor.IO.ByteArrayReader

// MetadataExtractor.IO.ByteArrayReader

// System.DateTime
struct DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_StaticFields
{
	// System.Int32[] System.DateTime::s_daysToMonth365
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___s_daysToMonth365_30;
	// System.Int32[] System.DateTime::s_daysToMonth366
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___s_daysToMonth366_31;
	// System.DateTime System.DateTime::MinValue
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___MinValue_32;
	// System.DateTime System.DateTime::MaxValue
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___MaxValue_33;
	// System.DateTime System.DateTime::UnixEpoch
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___UnixEpoch_34;
};

// System.DateTime

// System.Double

// System.Double

// MetadataExtractor.Formats.FileSystem.FileMetadataDirectory
struct FileMetadataDirectory_tFC758B6264064AE8FEF472AC8B8C5C5E74C1D647_StaticFields
{
	// System.Collections.Generic.Dictionary`2<System.Int32,System.String> MetadataExtractor.Formats.FileSystem.FileMetadataDirectory::_tagNameMap
	Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* ____tagNameMap_10;
};

// MetadataExtractor.Formats.FileSystem.FileMetadataDirectory

// System.Int32

// System.Int32

// System.Int64

// System.Int64

// System.IntPtr
struct IntPtr_t_StaticFields
{
	// System.IntPtr System.IntPtr::Zero
	intptr_t ___Zero_1;
};

// System.IntPtr

// System.SByte

// System.SByte

// MetadataExtractor.IO.SequentialByteArrayReader

// MetadataExtractor.IO.SequentialByteArrayReader

// MetadataExtractor.IO.SequentialStreamReader

// MetadataExtractor.IO.SequentialStreamReader

// System.Single

// System.Single

// System.IO.Stream
struct Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE_StaticFields
{
	// System.IO.Stream System.IO.Stream::Null
	Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___Null_1;
};

// System.IO.Stream

// System.TimeSpan
struct TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_StaticFields
{
	// System.TimeSpan System.TimeSpan::Zero
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___Zero_19;
	// System.TimeSpan System.TimeSpan::MaxValue
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___MaxValue_20;
	// System.TimeSpan System.TimeSpan::MinValue
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___MinValue_21;
};

// System.TimeSpan

// System.UInt16

// System.UInt16

// System.Void

// System.Void

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=10

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=10

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=12

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=12

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=16

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=16

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=162

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=162

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=168

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=168

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=20

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=20

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=3

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=3

// System.Exception
struct Exception_t_StaticFields
{
	// System.Object System.Exception::s_EDILock
	RuntimeObject* ___s_EDILock_0;
};

// System.Exception

// System.IO.FileStream
struct FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8_StaticFields
{
	// System.Byte[] System.IO.FileStream::buf_recycle
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___buf_recycle_4;
	// System.Object System.IO.FileStream::buf_recycle_lock
	RuntimeObject* ___buf_recycle_lock_5;
};

// System.IO.FileStream

// MetadataExtractor.Formats.Jpeg.JpegSegmentType

// MetadataExtractor.Formats.Jpeg.JpegSegmentType

// System.Func`2<MetadataExtractor.Formats.Jpeg.JpegSegment,System.Boolean>

// System.Func`2<MetadataExtractor.Formats.Jpeg.JpegSegment,System.Boolean>

// System.Func`2<MetadataExtractor.Formats.Jpeg.JpegSegment,MetadataExtractor.Directory>

// System.Func`2<MetadataExtractor.Formats.Jpeg.JpegSegment,MetadataExtractor.Directory>

// System.IO.IOException

// System.IO.IOException
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
	{
		m_Items[index] = value;
	}
};
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// MetadataExtractor.Formats.Jpeg.JpegSegmentType[]
struct JpegSegmentTypeU5BU5D_t84EA1C1277027054474CD7AF7079DB6B06020C4E  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
	{
		m_Items[index] = value;
	}
};
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


// System.Void MetadataExtractor.TagDescriptor`1<System.Object>::.ctor(T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TagDescriptor_1__ctor_m47697B1F7143F4334AECF37C6F04300C9DE28E03_gshared (TagDescriptor_1_t54DDB11CF6366D35183686BA442DEBB16FF64390* __this, RuntimeObject* ___0_directory, const RuntimeMethod* method) ;
// T MetadataExtractor.TagDescriptor`1<System.Object>::get_Directory()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* TagDescriptor_1_get_Directory_mAA3224DFCA53F7D6E690D426554A10AA3DD928E9_gshared_inline (TagDescriptor_1_t54DDB11CF6366D35183686BA442DEBB16FF64390* __this, const RuntimeMethod* method) ;
// System.String MetadataExtractor.TagDescriptor`1<System.Object>::GetDescription(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* TagDescriptor_1_GetDescription_mD1E215A227287FE4ABEA8026346CCA1418D99519_gshared (TagDescriptor_1_t54DDB11CF6366D35183686BA442DEBB16FF64390* __this, int32_t ___0_tagType, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m92E9AB321FBD7147CA109C822D99C8B0610C27B7_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::Add(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_mAF1EF7DA16BD70E252EA5C4B0F74DE519A02CBCD_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::AddRange(System.Collections.Generic.IEnumerable`1<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m1F76B300133150E6046C5FED00E88B5DE0A02E17_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::Add(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
// System.String MetadataExtractor.TagDescriptor`1<System.Object>::GetIndexedDescription(System.Int32,System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* TagDescriptor_1_GetIndexedDescription_m19F411847D2F65F3362BEB4C5BA991408B151EF6_gshared (TagDescriptor_1_t54DDB11CF6366D35183686BA442DEBB16FF64390* __this, int32_t ___0_tagType, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___1_descriptions, const RuntimeMethod* method) ;
// System.Void System.Func`2<System.Object,System.Boolean>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Func_2__ctor_m13C0A7F33154D861E2A041B52E88461832DA1697_gshared (Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable::Where<System.Object>(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Enumerable_Where_TisRuntimeObject_m5DAF16724887B42DDBBF391C7F375749E8AA4AD7_gshared (RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method) ;
// System.Void System.Func`2<System.Object,System.Object>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Func_2__ctor_m7F8A01C0B02BC1D4063F4EB1E817F7A48562A398_gshared (Func_2_tACBF5A1656250800CE861707354491F0611F6624* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable::Select<System.Object,System.Object>(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,TResult>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Enumerable_Select_TisRuntimeObject_TisRuntimeObject_m67C538A5EBF57C4844107A8EF25DB2CAAFBAF8FB_gshared (RuntimeObject* ___0_source, Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___1_selector, const RuntimeMethod* method) ;

// System.Void MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Avi.AviDirectory>::.ctor(T)
inline void TagDescriptor_1__ctor_m16606A064012009FF0396AC5D50BC57EBF9FC001 (TagDescriptor_1_t581EFB73E33C37F2BE9E941CD5ECE902A891428E* __this, AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* ___0_directory, const RuntimeMethod* method)
{
	((  void (*) (TagDescriptor_1_t581EFB73E33C37F2BE9E941CD5ECE902A891428E*, AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2*, const RuntimeMethod*))TagDescriptor_1__ctor_m47697B1F7143F4334AECF37C6F04300C9DE28E03_gshared)(__this, ___0_directory, method);
}
// T MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Avi.AviDirectory>::get_Directory()
inline AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* TagDescriptor_1_get_Directory_m8A529F98C29B4780346A184D79CAF1661EED33A9_inline (TagDescriptor_1_t581EFB73E33C37F2BE9E941CD5ECE902A891428E* __this, const RuntimeMethod* method)
{
	return ((  AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* (*) (TagDescriptor_1_t581EFB73E33C37F2BE9E941CD5ECE902A891428E*, const RuntimeMethod*))TagDescriptor_1_get_Directory_mAA3224DFCA53F7D6E690D426554A10AA3DD928E9_gshared_inline)(__this, method);
}
// System.String MetadataExtractor.DirectoryExtensions::GetString(MetadataExtractor.Directory,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* DirectoryExtensions_GetString_m15A857F6398798C6B1E71CF250243648404BE05C (Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A* ___0_directory, int32_t ___1_tagType, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
// System.String MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Avi.AviDirectory>::GetDescription(System.Int32)
inline String_t* TagDescriptor_1_GetDescription_m8B50EB473A93AAFE67E71A7A68C7EEB60019BB7E (TagDescriptor_1_t581EFB73E33C37F2BE9E941CD5ECE902A891428E* __this, int32_t ___0_tagType, const RuntimeMethod* method)
{
	return ((  String_t* (*) (TagDescriptor_1_t581EFB73E33C37F2BE9E941CD5ECE902A891428E*, int32_t, const RuntimeMethod*))TagDescriptor_1_GetDescription_mD1E215A227287FE4ABEA8026346CCA1418D99519_gshared)(__this, ___0_tagType, method);
}
// System.Void MetadataExtractor.Directory::.ctor(System.Collections.Generic.Dictionary`2<System.Int32,System.String>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Directory__ctor_mD2BF152CC7614DEA9399A677108666AF34DCA483 (Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A* __this, Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* ___0_tagNameMap, const RuntimeMethod* method) ;
// System.Void MetadataExtractor.Formats.Avi.AviDescriptor::.ctor(MetadataExtractor.Formats.Avi.AviDirectory)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AviDescriptor__ctor_m2497CA4427FDFE5267614CCCBE62074CFD33557D (AviDescriptor_t960F270A1DD847552FB983C076B5848D5A0DB623* __this, AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* ___0_directory, const RuntimeMethod* method) ;
// System.Void MetadataExtractor.Directory::SetDescriptor(MetadataExtractor.ITagDescriptor)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Directory_SetDescriptor_m9132B7EE403E6B6BF84E42AB6EBEFA7F49C8D1C2 (Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A* __this, RuntimeObject* ___0_descriptor, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.String>::.ctor()
inline void Dictionary_2__ctor_mC854597C0C338BBA12EE451456D8658DF6D01BD4 (Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9*, const RuntimeMethod*))Dictionary_2__ctor_m92E9AB321FBD7147CA109C822D99C8B0610C27B7_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.String>::Add(TKey,TValue)
inline void Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128 (Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* __this, int32_t ___0_key, String_t* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9*, int32_t, String_t*, const RuntimeMethod*))Dictionary_2_Add_mAF1EF7DA16BD70E252EA5C4B0F74DE519A02CBCD_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Void System.Collections.Generic.List`1<MetadataExtractor.Directory>::.ctor()
inline void List_1__ctor_m6929C72C345340E3A9577A6F480A8CD784A1DBBB (List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// System.Void System.IO.FileStream::.ctor(System.String,System.IO.FileMode,System.IO.FileAccess,System.IO.FileShare)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void FileStream__ctor_mA39506EF7A1F33FCA0199B880BE1D82217E33EEC (FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8* __this, String_t* ___0_path, int32_t ___1_mode, int32_t ___2_access, int32_t ___3_share, const RuntimeMethod* method) ;
// System.Collections.Generic.IReadOnlyList`1<MetadataExtractor.Directory> MetadataExtractor.Formats.Avi.AviMetadataReader::ReadMetadata(System.IO.Stream)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* AviMetadataReader_ReadMetadata_m43508BA05D604CE7A88EB29910DC78265F665212 (Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___0_stream, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<MetadataExtractor.Directory>::AddRange(System.Collections.Generic.IEnumerable`1<T>)
inline void List_1_AddRange_mA89FE5F3140BE378BAB28377FAB1EC903A27BA26 (List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0*, RuntimeObject*, const RuntimeMethod*))List_1_AddRange_m1F76B300133150E6046C5FED00E88B5DE0A02E17_gshared)(__this, ___0_collection, method);
}
// System.Void MetadataExtractor.Formats.FileSystem.FileMetadataReader::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void FileMetadataReader__ctor_m3EDC79BC837C7CDB8324638E5256E63051BC688A (FileMetadataReader_tF9C052702D0220FC039CB536D35F98640B92791B* __this, const RuntimeMethod* method) ;
// MetadataExtractor.Formats.FileSystem.FileMetadataDirectory MetadataExtractor.Formats.FileSystem.FileMetadataReader::Read(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR FileMetadataDirectory_tFC758B6264064AE8FEF472AC8B8C5C5E74C1D647* FileMetadataReader_Read_mDF9094363BEB1C24F1E4482118DE14E2CEE998FD (FileMetadataReader_tF9C052702D0220FC039CB536D35F98640B92791B* __this, String_t* ___0_file, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<MetadataExtractor.Directory>::Add(T)
inline void List_1_Add_m8C01AC4C40198210118E5E169A4FA596142917A6_inline (List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* __this, Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0*, Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Void MetadataExtractor.Formats.Riff.RiffReader::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RiffReader__ctor_m6F2803A10FB0FD9BA44196234D37BB05EB6A53A4 (RiffReader_t4FB59AD8B47193BCE6ECBEC717299EC0CD8C1F6F* __this, const RuntimeMethod* method) ;
// System.Void MetadataExtractor.IO.SequentialStreamReader::.ctor(System.IO.Stream,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SequentialStreamReader__ctor_m4EB8AF1A493215866F6DABE7642F30AD82AE92DA (SequentialStreamReader_t1D963C5D7C36DFC24FAE963ECEDBA4B82127EDE5* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___0_stream, bool ___1_isMotorolaByteOrder, const RuntimeMethod* method) ;
// System.Void MetadataExtractor.Formats.Avi.AviRiffHandler::.ctor(System.Collections.Generic.List`1<MetadataExtractor.Directory>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AviRiffHandler__ctor_m6702FA221890E2F1F98FE32E6A28F6EF0A413E70 (AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5* __this, List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* ___0_directories, const RuntimeMethod* method) ;
// System.Void MetadataExtractor.Formats.Riff.RiffReader::ProcessRiff(MetadataExtractor.IO.SequentialReader,MetadataExtractor.Formats.Riff.IRiffHandler)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RiffReader_ProcessRiff_m3E09AF0D722185626A8D012C59759DB56B13080F (RiffReader_t4FB59AD8B47193BCE6ECBEC717299EC0CD8C1F6F* __this, SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* ___0_reader, RuntimeObject* ___1_handler, const RuntimeMethod* method) ;
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Boolean System.String::op_Equality(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1 (String_t* ___0_a, String_t* ___1_b, const RuntimeMethod* method) ;
// System.Void MetadataExtractor.IO.ByteArrayReader::.ctor(System.Byte[],System.Int32,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ByteArrayReader__ctor_m9B95597991A73017EF2CEC40CAB69A560A89D137 (ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_buffer, int32_t ___1_baseOffset, bool ___2_isMotorolaByteOrder, const RuntimeMethod* method) ;
// MetadataExtractor.Formats.Avi.AviDirectory MetadataExtractor.Formats.Avi.AviRiffHandler::GetOrCreateAviDirectory()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* AviRiffHandler_GetOrCreateAviDirectory_m31016FEEABEF8391074705CAFBBC5051EC4BCD74 (AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5* __this, const RuntimeMethod* method) ;
// System.Text.Encoding System.Text.Encoding::get_ASCII()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* Encoding_get_ASCII_mCC61B512D320FD4E2E71CC0DFDF8DDF3CD215C65 (const RuntimeMethod* method) ;
// System.String MetadataExtractor.IO.IndexedReader::GetString(System.Int32,System.Int32,System.Text.Encoding)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* IndexedReader_GetString_m19BC68FA09D5030ECA3155E3ADBE883EFD7603A3 (IndexedReader_t22E754BF7EB6C22AD3812A7E1E2B44E0555B30C5* __this, int32_t ___0_index, int32_t ___1_bytesRequested, Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___2_encoding, const RuntimeMethod* method) ;
// System.Single MetadataExtractor.IO.IndexedReader::GetFloat32(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float IndexedReader_GetFloat32_mA57768A4FF8E20113048CC711121CEB7C088DEAA (IndexedReader_t22E754BF7EB6C22AD3812A7E1E2B44E0555B30C5* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Int32 MetadataExtractor.IO.IndexedReader::GetInt32(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t IndexedReader_GetInt32_m2E9FF8707E2C418B8D885A62FCFC9FE5E0769212 (IndexedReader_t22E754BF7EB6C22AD3812A7E1E2B44E0555B30C5* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Double System.Math::Pow(System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Math_Pow_mEAE651F0858203FBE12B72B6A53951BBD0FB5265 (double ___0_x, double ___1_y, const RuntimeMethod* method) ;
// System.Void System.TimeSpan::.ctor(System.Int32,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimeSpan__ctor_mF8B85616C009D35D860DA0254327E8AAF54822A1 (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A* __this, int32_t ___0_hours, int32_t ___1_minutes, int32_t ___2_seconds, const RuntimeMethod* method) ;
// System.Int64 System.TimeSpan::get_Ticks()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t TimeSpan_get_Ticks_mC50131E57621F29FACC53B3241432ABB874FA1B5_inline (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A* __this, const RuntimeMethod* method) ;
// System.Void System.DateTime::.ctor(System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DateTime__ctor_m64AFCE84ABB24698256EB9F635EFD0A221823441 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D* __this, int64_t ___0_ticks, const RuntimeMethod* method) ;
// System.String System.DateTime::ToString(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* DateTime_ToString_m6963A84785C320DA776C9FCFFEDAF26C8F1A8D78 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D* __this, String_t* ___0_format, const RuntimeMethod* method) ;
// System.Void MetadataExtractor.Directory::AddError(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Directory_AddError_mCF615646756A385CAEA6E2CC4FE68D64F4021A71 (Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A* __this, String_t* ___0_message, const RuntimeMethod* method) ;
// System.Int32 System.String::get_Length()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
// System.Boolean System.String::EndsWith(System.String,System.StringComparison)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_EndsWith_m5E5D307CA6AEB7C08CE782B4693B19D07ADC9075 (String_t* __this, String_t* ___0_value, int32_t ___1_comparisonType, const RuntimeMethod* method) ;
// System.String System.String::Substring(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE (String_t* __this, int32_t ___0_startIndex, int32_t ___1_length, const RuntimeMethod* method) ;
// System.Void MetadataExtractor.Formats.Avi.AviDirectory::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AviDirectory__ctor_mF28DB3DD363CC3CE48EC1AEA8EE504CBDAE655A4 (AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* __this, const RuntimeMethod* method) ;
// System.Void MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Adobe.AdobeJpegDirectory>::.ctor(T)
inline void TagDescriptor_1__ctor_m750C1E77A6F3FD3BEA349A0AE3CEF90B1E9E0038 (TagDescriptor_1_t79D01947DFE7B33543ECC55186FA0E26055A4102* __this, AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* ___0_directory, const RuntimeMethod* method)
{
	((  void (*) (TagDescriptor_1_t79D01947DFE7B33543ECC55186FA0E26055A4102*, AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0*, const RuntimeMethod*))TagDescriptor_1__ctor_m47697B1F7143F4334AECF37C6F04300C9DE28E03_gshared)(__this, ___0_directory, method);
}
// System.String MetadataExtractor.Formats.Adobe.AdobeJpegDescriptor::GetColorTransformDescription()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AdobeJpegDescriptor_GetColorTransformDescription_m0757DB296D04C5F6532A6DEAF8B7B7C0712135F2 (AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA* __this, const RuntimeMethod* method) ;
// System.String MetadataExtractor.Formats.Adobe.AdobeJpegDescriptor::GetDctEncodeVersionDescription()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AdobeJpegDescriptor_GetDctEncodeVersionDescription_mD5D67F79B4549CC8658FD583CBAA9CFBD78ED791 (AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA* __this, const RuntimeMethod* method) ;
// System.String MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Adobe.AdobeJpegDirectory>::GetDescription(System.Int32)
inline String_t* TagDescriptor_1_GetDescription_m2A08293E7212E61FB0ED1942A5196EAED8678E3F (TagDescriptor_1_t79D01947DFE7B33543ECC55186FA0E26055A4102* __this, int32_t ___0_tagType, const RuntimeMethod* method)
{
	return ((  String_t* (*) (TagDescriptor_1_t79D01947DFE7B33543ECC55186FA0E26055A4102*, int32_t, const RuntimeMethod*))TagDescriptor_1_GetDescription_mD1E215A227287FE4ABEA8026346CCA1418D99519_gshared)(__this, ___0_tagType, method);
}
// T MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Adobe.AdobeJpegDirectory>::get_Directory()
inline AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* TagDescriptor_1_get_Directory_mA075B82F615F061F332E7840C307691A66C87329_inline (TagDescriptor_1_t79D01947DFE7B33543ECC55186FA0E26055A4102* __this, const RuntimeMethod* method)
{
	return ((  AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* (*) (TagDescriptor_1_t79D01947DFE7B33543ECC55186FA0E26055A4102*, const RuntimeMethod*))TagDescriptor_1_get_Directory_mAA3224DFCA53F7D6E690D426554A10AA3DD928E9_gshared_inline)(__this, method);
}
// System.Boolean MetadataExtractor.DirectoryExtensions::TryGetInt32(MetadataExtractor.Directory,System.Int32,System.Int32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool DirectoryExtensions_TryGetInt32_mA630CA2333FB5523F5A7ACBBE927BF7798BAA6EB (Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A* ___0_directory, int32_t ___1_tagType, int32_t* ___2_value, const RuntimeMethod* method) ;
// System.String System.Int32::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
// System.String MetadataExtractor.TagDescriptor`1<MetadataExtractor.Formats.Adobe.AdobeJpegDirectory>::GetIndexedDescription(System.Int32,System.String[])
inline String_t* TagDescriptor_1_GetIndexedDescription_m3C183A03543A77AA047617C6C238F92C8A939D83 (TagDescriptor_1_t79D01947DFE7B33543ECC55186FA0E26055A4102* __this, int32_t ___0_tagType, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___1_descriptions, const RuntimeMethod* method)
{
	return ((  String_t* (*) (TagDescriptor_1_t79D01947DFE7B33543ECC55186FA0E26055A4102*, int32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*, const RuntimeMethod*))TagDescriptor_1_GetIndexedDescription_m19F411847D2F65F3362BEB4C5BA991408B151EF6_gshared)(__this, ___0_tagType, ___1_descriptions, method);
}
// System.Void MetadataExtractor.Formats.Adobe.AdobeJpegDescriptor::.ctor(MetadataExtractor.Formats.Adobe.AdobeJpegDirectory)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AdobeJpegDescriptor__ctor_mA8A8DB470DE70504A93AB0F0E05E9D7EBA1CB15D (AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA* __this, AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* ___0_directory, const RuntimeMethod* method) ;
// System.Void System.Func`2<MetadataExtractor.Formats.Jpeg.JpegSegment,System.Boolean>::.ctor(System.Object,System.IntPtr)
inline void Func_2__ctor_mAF6AF8B571A496F929570EA9A21B7E57C7D58995 (Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E*, RuntimeObject*, intptr_t, const RuntimeMethod*))Func_2__ctor_m13C0A7F33154D861E2A041B52E88461832DA1697_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable::Where<MetadataExtractor.Formats.Jpeg.JpegSegment>(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
inline RuntimeObject* Enumerable_Where_TisJpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF_m0B083B7D77A38F867CF69AFB17AB8E091FEA8902 (RuntimeObject* ___0_source, Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E* ___1_predicate, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RuntimeObject*, Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E*, const RuntimeMethod*))Enumerable_Where_TisRuntimeObject_m5DAF16724887B42DDBBF391C7F375749E8AA4AD7_gshared)(___0_source, ___1_predicate, method);
}
// System.Void System.Func`2<MetadataExtractor.Formats.Jpeg.JpegSegment,MetadataExtractor.Directory>::.ctor(System.Object,System.IntPtr)
inline void Func_2__ctor_m3D81874EE3BDF42CA1D8E39EAD8F37A634268B49 (Func_2_t679C7E0EDC405525B5A0DB02A53918AA6DD25D08* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Func_2_t679C7E0EDC405525B5A0DB02A53918AA6DD25D08*, RuntimeObject*, intptr_t, const RuntimeMethod*))Func_2__ctor_m7F8A01C0B02BC1D4063F4EB1E817F7A48562A398_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable::Select<MetadataExtractor.Formats.Jpeg.JpegSegment,MetadataExtractor.Directory>(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,TResult>)
inline RuntimeObject* Enumerable_Select_TisJpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF_TisDirectory_t3179A156C81D90563D22A0D009C0821CE27FA51A_m4DC39D0F277FD093C793D8677DAF1293E6C334C8 (RuntimeObject* ___0_source, Func_2_t679C7E0EDC405525B5A0DB02A53918AA6DD25D08* ___1_selector, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RuntimeObject*, Func_2_t679C7E0EDC405525B5A0DB02A53918AA6DD25D08*, const RuntimeMethod*))Enumerable_Select_TisRuntimeObject_TisRuntimeObject_m67C538A5EBF57C4844107A8EF25DB2CAAFBAF8FB_gshared)(___0_source, ___1_selector, method);
}
// System.Void MetadataExtractor.Formats.Adobe.AdobeJpegDirectory::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AdobeJpegDirectory__ctor_m4BEE34709439DFD358A2ADB76E0757F9B61218D7 (AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* __this, const RuntimeMethod* method) ;
// System.String MetadataExtractor.IO.SequentialReader::GetString(System.Int32,System.Text.Encoding)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SequentialReader_GetString_m4A751A777A3358AB16636345345F373627952B75 (SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* __this, int32_t ___0_bytesRequested, Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___1_encoding, const RuntimeMethod* method) ;
// System.Boolean System.String::op_Inequality(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_op_Inequality_m8C940F3CFC42866709D7CA931B3D77B4BE94BCB6 (String_t* ___0_a, String_t* ___1_b, const RuntimeMethod* method) ;
// System.UInt16 MetadataExtractor.IO.SequentialReader::GetUInt16()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t SequentialReader_GetUInt16_mD37475AB2EA4490FDD658E33790E36718FEFF36A (SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* __this, const RuntimeMethod* method) ;
// System.SByte MetadataExtractor.IO.SequentialReader::GetSByte()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int8_t SequentialReader_GetSByte_m4AAD5E3C161C8E3056EB1399701A1759549255F2 (SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* __this, const RuntimeMethod* method) ;
// System.Byte[] MetadataExtractor.Formats.Jpeg.JpegSegment::get_Bytes()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* JpegSegment_get_Bytes_m50D5327094CC55158C7A61B0DD5045020AB48638_inline (JpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF* __this, const RuntimeMethod* method) ;
// System.Void MetadataExtractor.IO.SequentialByteArrayReader::.ctor(System.Byte[],System.Int32,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SequentialByteArrayReader__ctor_m886E431061EFEA9CD76547C61DDFC0AA9B6E7654 (SequentialByteArrayReader_t56E08F41E026F2B557D64F7199F9A5FBFE7D7829* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_bytes, int32_t ___1_baseIndex, bool ___2_isMotorolaByteOrder, const RuntimeMethod* method) ;
// MetadataExtractor.Formats.Adobe.AdobeJpegDirectory MetadataExtractor.Formats.Adobe.AdobeJpegReader::Extract(MetadataExtractor.IO.SequentialReader)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* AdobeJpegReader_Extract_m45C3F2449ADA365EEFB5B469A89346094E6AE0BE (AdobeJpegReader_t56227C3FB644AA11F0432D3331E7C5AB9872FBE5* __this, SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* ___0_reader, const RuntimeMethod* method) ;
// System.Void MetadataExtractor.Formats.Adobe.AdobeJpegReader/<>c::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_mDF20E74AAA720E9D19B50A9B48E409BD93F2BA95 (U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53* __this, const RuntimeMethod* method) ;
// System.Text.Encoding System.Text.Encoding::get_UTF8()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9 (const RuntimeMethod* method) ;
// System.Boolean System.String::Equals(System.String,System.StringComparison)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_Equals_m7BDFC0B951005B9DC2BAED464AFE68FF7E9ACE5A (String_t* __this, String_t* ___0_value, int32_t ___1_comparisonType, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MetadataExtractor.Formats.Avi.AviDescriptor::.ctor(MetadataExtractor.Formats.Avi.AviDirectory)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AviDescriptor__ctor_m2497CA4427FDFE5267614CCCBE62074CFD33557D (AviDescriptor_t960F270A1DD847552FB983C076B5848D5A0DB623* __this, AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* ___0_directory, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TagDescriptor_1__ctor_m16606A064012009FF0396AC5D50BC57EBF9FC001_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_0 = ___0_directory;
		TagDescriptor_1__ctor_m16606A064012009FF0396AC5D50BC57EBF9FC001(__this, L_0, TagDescriptor_1__ctor_m16606A064012009FF0396AC5D50BC57EBF9FC001_RuntimeMethod_var);
		return;
	}
}
// System.String MetadataExtractor.Formats.Avi.AviDescriptor::GetDescription(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AviDescriptor_GetDescription_mE7B67EB99F2480D2D1C2B8923D9E8C0BB6C52CF1 (AviDescriptor_t960F270A1DD847552FB983C076B5848D5A0DB623* __this, int32_t ___0_tagType, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DirectoryExtensions_t2A0E3E30420855CA057298B18B2396625DDF5E1D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TagDescriptor_1_GetDescription_m8B50EB473A93AAFE67E71A7A68C7EEB60019BB7E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TagDescriptor_1_get_Directory_m8A529F98C29B4780346A184D79CAF1661EED33A9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA8B876E75236FD879B6F61E168F508D2FDE6C753);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___0_tagType;
		if ((!(((uint32_t)((int32_t)il2cpp_codegen_subtract(L_0, 6))) <= ((uint32_t)1))))
		{
			goto IL_001d;
		}
	}
	{
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_1;
		L_1 = TagDescriptor_1_get_Directory_m8A529F98C29B4780346A184D79CAF1661EED33A9_inline(__this, TagDescriptor_1_get_Directory_m8A529F98C29B4780346A184D79CAF1661EED33A9_RuntimeMethod_var);
		int32_t L_2 = ___0_tagType;
		il2cpp_codegen_runtime_class_init_inline(DirectoryExtensions_t2A0E3E30420855CA057298B18B2396625DDF5E1D_il2cpp_TypeInfo_var);
		String_t* L_3;
		L_3 = DirectoryExtensions_GetString_m15A857F6398798C6B1E71CF250243648404BE05C(L_1, L_2, NULL);
		String_t* L_4;
		L_4 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_3, _stringLiteralA8B876E75236FD879B6F61E168F508D2FDE6C753, NULL);
		return L_4;
	}

IL_001d:
	{
		int32_t L_5 = ___0_tagType;
		String_t* L_6;
		L_6 = TagDescriptor_1_GetDescription_m8B50EB473A93AAFE67E71A7A68C7EEB60019BB7E(__this, L_5, TagDescriptor_1_GetDescription_m8B50EB473A93AAFE67E71A7A68C7EEB60019BB7E_RuntimeMethod_var);
		return L_6;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MetadataExtractor.Formats.Avi.AviDirectory::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AviDirectory__ctor_mF28DB3DD363CC3CE48EC1AEA8EE504CBDAE655A4 (AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AviDescriptor_t960F270A1DD847552FB983C076B5848D5A0DB623_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_il2cpp_TypeInfo_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_0 = ((AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_StaticFields*)il2cpp_codegen_static_fields_for(AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_il2cpp_TypeInfo_var))->____tagNameMap_16;
		il2cpp_codegen_runtime_class_init_inline(Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A_il2cpp_TypeInfo_var);
		Directory__ctor_mD2BF152CC7614DEA9399A677108666AF34DCA483(__this, L_0, NULL);
		AviDescriptor_t960F270A1DD847552FB983C076B5848D5A0DB623* L_1 = (AviDescriptor_t960F270A1DD847552FB983C076B5848D5A0DB623*)il2cpp_codegen_object_new(AviDescriptor_t960F270A1DD847552FB983C076B5848D5A0DB623_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		AviDescriptor__ctor_m2497CA4427FDFE5267614CCCBE62074CFD33557D(L_1, __this, NULL);
		Directory_SetDescriptor_m9132B7EE403E6B6BF84E42AB6EBEFA7F49C8D1C2(__this, L_1, NULL);
		return;
	}
}
// System.String MetadataExtractor.Formats.Avi.AviDirectory::get_Name()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AviDirectory_get_Name_m432E6519894FCA17E91FE09A0A1E418E92C8C919 (AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0978FD46E12CEBAC1D88B02D0DAA2E2F3A201C72);
		s_Il2CppMethodInitialized = true;
	}
	{
		return _stringLiteral0978FD46E12CEBAC1D88B02D0DAA2E2F3A201C72;
	}
}
// System.Void MetadataExtractor.Formats.Avi.AviDirectory::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AviDirectory__cctor_mA16D7009DD4E19509BA9E2299AAA340886EEA1F9 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mC854597C0C338BBA12EE451456D8658DF6D01BD4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral064FE1C639C81D5F3142367FD90FD448C4488741);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral30F39003DB1F504B0EE157F9D8ED6AE9C278239F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral344E909CD08D994F8FC624350866CAE2DF2D2BD0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral65962AB7981D7DED4606F8986A6AA25EAE045B40);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA8A3DD69001985C64C03CED9DF19EB43748F7283);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralEB39CBBCF7B7F393A23C0D8D902221EDE9A739DA);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF37C9765467D4EA1B14DD2BA48881A211A3B8C06);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF4C8E44AADA30D965F3A1F9F20D08293CC5C8ABC);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFBA5ADEA08A8958332ED2BC70EC48D3A8987BAED);
		s_Il2CppMethodInitialized = true;
	}
	{
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_0 = (Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9*)il2cpp_codegen_object_new(Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mC854597C0C338BBA12EE451456D8658DF6D01BD4(L_0, Dictionary_2__ctor_mC854597C0C338BBA12EE451456D8658DF6D01BD4_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_1 = L_0;
		NullCheck(L_1);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_1, 1, _stringLiteral064FE1C639C81D5F3142367FD90FD448C4488741, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_2 = L_1;
		NullCheck(L_2);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_2, 2, _stringLiteral30F39003DB1F504B0EE157F9D8ED6AE9C278239F, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_3 = L_2;
		NullCheck(L_3);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_3, 3, _stringLiteral65962AB7981D7DED4606F8986A6AA25EAE045B40, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_4 = L_3;
		NullCheck(L_4);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_4, 4, _stringLiteralF4C8E44AADA30D965F3A1F9F20D08293CC5C8ABC, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_5 = L_4;
		NullCheck(L_5);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_5, 5, _stringLiteralEB39CBBCF7B7F393A23C0D8D902221EDE9A739DA, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_6 = L_5;
		NullCheck(L_6);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_6, 6, _stringLiteralA8A3DD69001985C64C03CED9DF19EB43748F7283, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_7 = L_6;
		NullCheck(L_7);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_7, 7, _stringLiteralFBA5ADEA08A8958332ED2BC70EC48D3A8987BAED, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_8 = L_7;
		NullCheck(L_8);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_8, 8, _stringLiteral344E909CD08D994F8FC624350866CAE2DF2D2BD0, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_9 = L_8;
		NullCheck(L_9);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_9, ((int32_t)320), _stringLiteralF37C9765467D4EA1B14DD2BA48881A211A3B8C06, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		((AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_StaticFields*)il2cpp_codegen_static_fields_for(AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_il2cpp_TypeInfo_var))->____tagNameMap_16 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&((AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_StaticFields*)il2cpp_codegen_static_fields_for(AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_il2cpp_TypeInfo_var))->____tagNameMap_16), (void*)L_9);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Collections.Generic.IReadOnlyList`1<MetadataExtractor.Directory> MetadataExtractor.Formats.Avi.AviMetadataReader::ReadMetadata(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* AviMetadataReader_ReadMetadata_m388062C676C0CD5595DB83819D3085DA27E0FAB7 (String_t* ___0_filePath, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&FileMetadataReader_tF9C052702D0220FC039CB536D35F98640B92791B_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_AddRange_mA89FE5F3140BE378BAB28377FAB1EC903A27BA26_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m8C01AC4C40198210118E5E169A4FA596142917A6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m6929C72C345340E3A9577A6F480A8CD784A1DBBB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* V_0 = NULL;
	FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8* V_1 = NULL;
	{
		List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* L_0 = (List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0*)il2cpp_codegen_object_new(List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		List_1__ctor_m6929C72C345340E3A9577A6F480A8CD784A1DBBB(L_0, List_1__ctor_m6929C72C345340E3A9577A6F480A8CD784A1DBBB_RuntimeMethod_var);
		V_0 = L_0;
		String_t* L_1 = ___0_filePath;
		FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8* L_2 = (FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8*)il2cpp_codegen_object_new(FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		FileStream__ctor_mA39506EF7A1F33FCA0199B880BE1D82217E33EEC(L_2, L_1, 3, 1, 1, NULL);
		V_1 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_001e:
			{// begin finally (depth: 1)
				{
					FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8* L_3 = V_1;
					if (!L_3)
					{
						goto IL_0027;
					}
				}
				{
					FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8* L_4 = V_1;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_0027:
				{
					return;
				}
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* L_5 = V_0;
			FileStream_t07C7222EE10B75F352B89B76E60820160FF10AD8* L_6 = V_1;
			RuntimeObject* L_7;
			L_7 = AviMetadataReader_ReadMetadata_m43508BA05D604CE7A88EB29910DC78265F665212(L_6, NULL);
			NullCheck(L_5);
			List_1_AddRange_mA89FE5F3140BE378BAB28377FAB1EC903A27BA26(L_5, L_7, List_1_AddRange_mA89FE5F3140BE378BAB28377FAB1EC903A27BA26_RuntimeMethod_var);
			goto IL_0028;
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0028:
	{
		List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* L_8 = V_0;
		FileMetadataReader_tF9C052702D0220FC039CB536D35F98640B92791B* L_9 = (FileMetadataReader_tF9C052702D0220FC039CB536D35F98640B92791B*)il2cpp_codegen_object_new(FileMetadataReader_tF9C052702D0220FC039CB536D35F98640B92791B_il2cpp_TypeInfo_var);
		NullCheck(L_9);
		FileMetadataReader__ctor_m3EDC79BC837C7CDB8324638E5256E63051BC688A(L_9, NULL);
		String_t* L_10 = ___0_filePath;
		NullCheck(L_9);
		FileMetadataDirectory_tFC758B6264064AE8FEF472AC8B8C5C5E74C1D647* L_11;
		L_11 = FileMetadataReader_Read_mDF9094363BEB1C24F1E4482118DE14E2CEE998FD(L_9, L_10, NULL);
		NullCheck(L_8);
		List_1_Add_m8C01AC4C40198210118E5E169A4FA596142917A6_inline(L_8, L_11, List_1_Add_m8C01AC4C40198210118E5E169A4FA596142917A6_RuntimeMethod_var);
		List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* L_12 = V_0;
		return L_12;
	}
}
// System.Collections.Generic.IReadOnlyList`1<MetadataExtractor.Directory> MetadataExtractor.Formats.Avi.AviMetadataReader::ReadMetadata(System.IO.Stream)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* AviMetadataReader_ReadMetadata_m43508BA05D604CE7A88EB29910DC78265F665212 (Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___0_stream, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m6929C72C345340E3A9577A6F480A8CD784A1DBBB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RiffReader_t4FB59AD8B47193BCE6ECBEC717299EC0CD8C1F6F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SequentialStreamReader_t1D963C5D7C36DFC24FAE963ECEDBA4B82127EDE5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* V_0 = NULL;
	{
		List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* L_0 = (List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0*)il2cpp_codegen_object_new(List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		List_1__ctor_m6929C72C345340E3A9577A6F480A8CD784A1DBBB(L_0, List_1__ctor_m6929C72C345340E3A9577A6F480A8CD784A1DBBB_RuntimeMethod_var);
		V_0 = L_0;
		RiffReader_t4FB59AD8B47193BCE6ECBEC717299EC0CD8C1F6F* L_1 = (RiffReader_t4FB59AD8B47193BCE6ECBEC717299EC0CD8C1F6F*)il2cpp_codegen_object_new(RiffReader_t4FB59AD8B47193BCE6ECBEC717299EC0CD8C1F6F_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		RiffReader__ctor_m6F2803A10FB0FD9BA44196234D37BB05EB6A53A4(L_1, NULL);
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_2 = ___0_stream;
		SequentialStreamReader_t1D963C5D7C36DFC24FAE963ECEDBA4B82127EDE5* L_3 = (SequentialStreamReader_t1D963C5D7C36DFC24FAE963ECEDBA4B82127EDE5*)il2cpp_codegen_object_new(SequentialStreamReader_t1D963C5D7C36DFC24FAE963ECEDBA4B82127EDE5_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		SequentialStreamReader__ctor_m4EB8AF1A493215866F6DABE7642F30AD82AE92DA(L_3, L_2, (bool)1, NULL);
		List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* L_4 = V_0;
		AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5* L_5 = (AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5*)il2cpp_codegen_object_new(AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		AviRiffHandler__ctor_m6702FA221890E2F1F98FE32E6A28F6EF0A413E70(L_5, L_4, NULL);
		NullCheck(L_1);
		RiffReader_ProcessRiff_m3E09AF0D722185626A8D012C59759DB56B13080F(L_1, L_3, L_5, NULL);
		List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* L_6 = V_0;
		return L_6;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MetadataExtractor.Formats.Avi.AviRiffHandler::.ctor(System.Collections.Generic.List`1<MetadataExtractor.Directory>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AviRiffHandler__ctor_m6702FA221890E2F1F98FE32E6A28F6EF0A413E70 (AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5* __this, List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* ___0_directories, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* L_0 = ___0_directories;
		__this->____directories_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____directories_0), (void*)L_0);
		return;
	}
}
// System.Boolean MetadataExtractor.Formats.Avi.AviRiffHandler::ShouldAcceptRiffIdentifier(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool AviRiffHandler_ShouldAcceptRiffIdentifier_mC8972D5A9CAC7DE705E3B1015676B1BC2AB1311B (AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5* __this, String_t* ___0_identifier, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral48ECEE4566B670DF276CFBA62874E0AB6F2E9D7A);
		s_Il2CppMethodInitialized = true;
	}
	{
		String_t* L_0 = ___0_identifier;
		bool L_1;
		L_1 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_0, _stringLiteral48ECEE4566B670DF276CFBA62874E0AB6F2E9D7A, NULL);
		return L_1;
	}
}
// System.Boolean MetadataExtractor.Formats.Avi.AviRiffHandler::ShouldAcceptChunk(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool AviRiffHandler_ShouldAcceptChunk_mAE95ACE99633F8B31AD1C5EB7D5E09FF72E8FF96 (AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5* __this, String_t* ___0_fourCc, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0BA78D96D07EAF82150E77394E877D66DF74C1EF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1CBED9D36BAFE97D121834BB68CDA8E193A8E56D);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBF51FA64951F7449D906BFEB40DDC7E3B1F44CBF);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		String_t* L_0 = ___0_fourCc;
		bool L_1;
		L_1 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_0, _stringLiteral1CBED9D36BAFE97D121834BB68CDA8E193A8E56D, NULL);
		if (L_1)
		{
			goto IL_0029;
		}
	}
	{
		String_t* L_2 = ___0_fourCc;
		bool L_3;
		L_3 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_2, _stringLiteralBF51FA64951F7449D906BFEB40DDC7E3B1F44CBF, NULL);
		if (L_3)
		{
			goto IL_002d;
		}
	}
	{
		String_t* L_4 = ___0_fourCc;
		bool L_5;
		L_5 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_4, _stringLiteral0BA78D96D07EAF82150E77394E877D66DF74C1EF, NULL);
		if (L_5)
		{
			goto IL_0031;
		}
	}
	{
		goto IL_0035;
	}

IL_0029:
	{
		V_0 = (bool)1;
		goto IL_0037;
	}

IL_002d:
	{
		V_0 = (bool)1;
		goto IL_0037;
	}

IL_0031:
	{
		V_0 = (bool)1;
		goto IL_0037;
	}

IL_0035:
	{
		V_0 = (bool)0;
	}

IL_0037:
	{
		bool L_6 = V_0;
		return L_6;
	}
}
// System.Boolean MetadataExtractor.Formats.Avi.AviRiffHandler::ShouldAcceptList(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool AviRiffHandler_ShouldAcceptList_m986D21D652806A515E0D077CF6A74C5B2E488530 (AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5* __this, String_t* ___0_fourCc, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral48ECEE4566B670DF276CFBA62874E0AB6F2E9D7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4A4B98C54B2B1646B779755C6E122D933AD6CBB9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA8080615DB133763964A575ADBD1FBB06D00D893);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		String_t* L_0 = ___0_fourCc;
		bool L_1;
		L_1 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_0, _stringLiteral4A4B98C54B2B1646B779755C6E122D933AD6CBB9, NULL);
		if (L_1)
		{
			goto IL_0029;
		}
	}
	{
		String_t* L_2 = ___0_fourCc;
		bool L_3;
		L_3 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_2, _stringLiteralA8080615DB133763964A575ADBD1FBB06D00D893, NULL);
		if (L_3)
		{
			goto IL_002d;
		}
	}
	{
		String_t* L_4 = ___0_fourCc;
		bool L_5;
		L_5 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_4, _stringLiteral48ECEE4566B670DF276CFBA62874E0AB6F2E9D7A, NULL);
		if (L_5)
		{
			goto IL_0031;
		}
	}
	{
		goto IL_0035;
	}

IL_0029:
	{
		V_0 = (bool)1;
		goto IL_0037;
	}

IL_002d:
	{
		V_0 = (bool)1;
		goto IL_0037;
	}

IL_0031:
	{
		V_0 = (bool)1;
		goto IL_0037;
	}

IL_0035:
	{
		V_0 = (bool)0;
	}

IL_0037:
	{
		bool L_6 = V_0;
		return L_6;
	}
}
// System.Void MetadataExtractor.Formats.Avi.AviRiffHandler::ProcessChunk(System.String,System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AviRiffHandler_ProcessChunk_m65540DA9E8430DE9DDE03122A69065137F2B8E8E (AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5* __this, String_t* ___0_fourCc, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___1_payload, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0BA78D96D07EAF82150E77394E877D66DF74C1EF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1CBED9D36BAFE97D121834BB68CDA8E193A8E56D);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral92094BBD8DE1A81022C0FCA98F179197BA588E99);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA39994C06ED3CE0D019E2021E3F684287743F375);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBF51FA64951F7449D906BFEB40DDC7E3B1F44CBF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC124374D124AF1895C0D2EAF802B3DB47E24A2BA);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralEB408DDC4FA484E6BEFDF5954E56A2198C7A9FAB);
		s_Il2CppMethodInitialized = true;
	}
	ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* V_0 = NULL;
	AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* V_1 = NULL;
	String_t* V_2 = NULL;
	String_t* V_3 = NULL;
	float V_4 = 0.0f;
	float V_5 = 0.0f;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	String_t* V_10 = NULL;
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A V_11;
	memset((&V_11), 0, sizeof(V_11));
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D V_12;
	memset((&V_12), 0, sizeof(V_12));
	IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910* V_13 = NULL;
	AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* V_14 = NULL;
	ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* V_15 = NULL;
	int32_t V_16 = 0;
	int32_t V_17 = 0;
	int32_t V_18 = 0;
	IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910* V_19 = NULL;
	String_t* V_20 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		String_t* L_0 = ___0_fourCc;
		bool L_1;
		L_1 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_0, _stringLiteral1CBED9D36BAFE97D121834BB68CDA8E193A8E56D, NULL);
		if (L_1)
		{
			goto IL_002e;
		}
	}
	{
		String_t* L_2 = ___0_fourCc;
		bool L_3;
		L_3 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_2, _stringLiteralBF51FA64951F7449D906BFEB40DDC7E3B1F44CBF, NULL);
		if (L_3)
		{
			goto IL_0187;
		}
	}
	{
		String_t* L_4 = ___0_fourCc;
		bool L_5;
		L_5 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_4, _stringLiteral0BA78D96D07EAF82150E77394E877D66DF74C1EF, NULL);
		if (L_5)
		{
			goto IL_0205;
		}
	}
	{
		return;
	}

IL_002e:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = ___1_payload;
		ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* L_7 = (ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F*)il2cpp_codegen_object_new(ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F_il2cpp_TypeInfo_var);
		NullCheck(L_7);
		ByteArrayReader__ctor_m9B95597991A73017EF2CEC40CAB69A560A89D137(L_7, L_6, 0, (bool)0, NULL);
		V_0 = L_7;
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_8;
		L_8 = AviRiffHandler_GetOrCreateAviDirectory_m31016FEEABEF8391074705CAFBBC5051EC4BCD74(__this, NULL);
		V_1 = L_8;
	}
	try
	{// begin try (depth: 1)
		{
			ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* L_9 = V_0;
			Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_10;
			L_10 = Encoding_get_ASCII_mCC61B512D320FD4E2E71CC0DFDF8DDF3CD215C65(NULL);
			NullCheck(L_9);
			String_t* L_11;
			L_11 = IndexedReader_GetString_m19BC68FA09D5030ECA3155E3ADBE883EFD7603A3(L_9, 0, 4, L_10, NULL);
			V_2 = L_11;
			ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* L_12 = V_0;
			Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_13;
			L_13 = Encoding_get_ASCII_mCC61B512D320FD4E2E71CC0DFDF8DDF3CD215C65(NULL);
			NullCheck(L_12);
			String_t* L_14;
			L_14 = IndexedReader_GetString_m19BC68FA09D5030ECA3155E3ADBE883EFD7603A3(L_12, 4, 4, L_13, NULL);
			V_3 = L_14;
			ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* L_15 = V_0;
			NullCheck(L_15);
			float L_16;
			L_16 = IndexedReader_GetFloat32_mA57768A4FF8E20113048CC711121CEB7C088DEAA(L_15, ((int32_t)20), NULL);
			V_4 = L_16;
			ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* L_17 = V_0;
			NullCheck(L_17);
			float L_18;
			L_18 = IndexedReader_GetFloat32_mA57768A4FF8E20113048CC711121CEB7C088DEAA(L_17, ((int32_t)24), NULL);
			V_5 = L_18;
			ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* L_19 = V_0;
			NullCheck(L_19);
			int32_t L_20;
			L_20 = IndexedReader_GetInt32_m2E9FF8707E2C418B8D885A62FCFC9FE5E0769212(L_19, ((int32_t)32), NULL);
			V_6 = L_20;
			String_t* L_21 = V_2;
			bool L_22;
			L_22 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_21, _stringLiteralC124374D124AF1895C0D2EAF802B3DB47E24A2BA, NULL);
			if (!L_22)
			{
				goto IL_0146_1;
			}
		}
		{
			AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_23 = V_1;
			float L_24 = V_5;
			float L_25 = V_4;
			float L_26 = ((float)(L_24/L_25));
			RuntimeObject* L_27 = Box(Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, &L_26);
			NullCheck(L_23);
			VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_23, 1, L_27);
			int32_t L_28 = V_6;
			float L_29 = V_5;
			float L_30 = V_4;
			double L_31 = ((double)((float)(((float)L_28)/((float)(L_29/L_30)))));
			il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
			double L_32;
			L_32 = Math_Pow_mEAE651F0858203FBE12B72B6A53951BBD0FB5265((60.0), (2.0), NULL);
			V_7 = ((int32_t)(il2cpp_codegen_cast_double_to_int<int32_t>(L_31)/il2cpp_codegen_cast_double_to_int<int32_t>(L_32)));
			double L_33 = L_31;
			double L_34;
			L_34 = Math_Pow_mEAE651F0858203FBE12B72B6A53951BBD0FB5265((60.0), (1.0), NULL);
			int32_t L_35 = V_7;
			V_8 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(il2cpp_codegen_cast_double_to_int<int32_t>(L_33)/il2cpp_codegen_cast_double_to_int<int32_t>(L_34))), ((int32_t)il2cpp_codegen_multiply(L_35, ((int32_t)60)))));
			double L_36;
			L_36 = Math_Pow_mEAE651F0858203FBE12B72B6A53951BBD0FB5265((60.0), (0.0), NULL);
			int32_t L_37 = V_8;
			double L_38;
			L_38 = bankers_round(((double)il2cpp_codegen_subtract(((double)(L_33/L_36)), ((double)((int32_t)il2cpp_codegen_multiply(L_37, ((int32_t)60)))))));
			V_9 = il2cpp_codegen_cast_double_to_int<int32_t>(L_38);
			int32_t L_39 = V_7;
			int32_t L_40 = V_8;
			int32_t L_41 = V_9;
			TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_42;
			memset((&L_42), 0, sizeof(L_42));
			TimeSpan__ctor_mF8B85616C009D35D860DA0254327E8AAF54822A1((&L_42), L_39, L_40, L_41, /*hidden argument*/NULL);
			V_11 = L_42;
			int64_t L_43;
			L_43 = TimeSpan_get_Ticks_mC50131E57621F29FACC53B3241432ABB874FA1B5_inline((&V_11), NULL);
			DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_44;
			memset((&L_44), 0, sizeof(L_44));
			DateTime__ctor_m64AFCE84ABB24698256EB9F635EFD0A221823441((&L_44), L_43, /*hidden argument*/NULL);
			V_12 = L_44;
			String_t* L_45;
			L_45 = DateTime_ToString_m6963A84785C320DA776C9FCFFEDAF26C8F1A8D78((&V_12), _stringLiteral92094BBD8DE1A81022C0FCA98F179197BA588E99, NULL);
			V_10 = L_45;
			AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_46 = V_1;
			String_t* L_47 = V_10;
			NullCheck(L_46);
			VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_46, 3, L_47);
			AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_48 = V_1;
			String_t* L_49 = V_3;
			NullCheck(L_48);
			VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_48, 4, L_49);
			goto IL_0164_1;
		}

IL_0146_1:
		{
			String_t* L_50 = V_2;
			bool L_51;
			L_51 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_50, _stringLiteralA39994C06ED3CE0D019E2021E3F684287743F375, NULL);
			if (!L_51)
			{
				goto IL_0164_1;
			}
		}
		{
			AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_52 = V_1;
			float L_53 = V_5;
			float L_54 = V_4;
			float L_55 = ((float)(L_53/L_54));
			RuntimeObject* L_56 = Box(Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, &L_55);
			NullCheck(L_52);
			VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_52, 2, L_56);
		}

IL_0164_1:
		{
			goto IL_0255;
		}
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0169;
		}
		throw e;
	}

CATCH_0169:
	{// begin catch(System.IO.IOException)
		V_13 = ((IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910*)IL2CPP_GET_ACTIVE_EXCEPTION(IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910*));
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_57 = V_1;
		IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910* L_58 = V_13;
		NullCheck(L_58);
		String_t* L_59;
		L_59 = VirtualFuncInvoker0< String_t* >::Invoke(5 /* System.String System.Exception::get_Message() */, L_58);
		String_t* L_60;
		L_60 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralFA547AA5C8BB8C7AA96008C6E522BDDA8C5207D5)), L_59, NULL);
		NullCheck(L_57);
		Directory_AddError_mCF615646756A385CAEA6E2CC4FE68D64F4021A71(L_57, L_60, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION();
		goto IL_0255;
	}// end catch (depth: 1)

IL_0187:
	{
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_61;
		L_61 = AviRiffHandler_GetOrCreateAviDirectory_m31016FEEABEF8391074705CAFBBC5051EC4BCD74(__this, NULL);
		V_14 = L_61;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_62 = ___1_payload;
		ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* L_63 = (ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F*)il2cpp_codegen_object_new(ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F_il2cpp_TypeInfo_var);
		NullCheck(L_63);
		ByteArrayReader__ctor_m9B95597991A73017EF2CEC40CAB69A560A89D137(L_63, L_62, 0, (bool)0, NULL);
		V_15 = L_63;
	}
	try
	{// begin try (depth: 1)
		ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* L_64 = V_15;
		NullCheck(L_64);
		int32_t L_65;
		L_65 = IndexedReader_GetInt32_m2E9FF8707E2C418B8D885A62FCFC9FE5E0769212(L_64, ((int32_t)24), NULL);
		V_16 = L_65;
		ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* L_66 = V_15;
		NullCheck(L_66);
		int32_t L_67;
		L_67 = IndexedReader_GetInt32_m2E9FF8707E2C418B8D885A62FCFC9FE5E0769212(L_66, ((int32_t)32), NULL);
		V_17 = L_67;
		ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* L_68 = V_15;
		NullCheck(L_68);
		int32_t L_69;
		L_69 = IndexedReader_GetInt32_m2E9FF8707E2C418B8D885A62FCFC9FE5E0769212(L_68, ((int32_t)36), NULL);
		V_18 = L_69;
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_70 = V_14;
		int32_t L_71 = V_17;
		int32_t L_72 = L_71;
		RuntimeObject* L_73 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_72);
		NullCheck(L_70);
		VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_70, 6, L_73);
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_74 = V_14;
		int32_t L_75 = V_18;
		int32_t L_76 = L_75;
		RuntimeObject* L_77 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_76);
		NullCheck(L_74);
		VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_74, 7, L_77);
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_78 = V_14;
		int32_t L_79 = V_16;
		int32_t L_80 = L_79;
		RuntimeObject* L_81 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_80);
		NullCheck(L_78);
		VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_78, 8, L_81);
		goto IL_0255;
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_01e9;
		}
		throw e;
	}

CATCH_01e9:
	{// begin catch(System.IO.IOException)
		V_19 = ((IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910*)IL2CPP_GET_ACTIVE_EXCEPTION(IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910*));
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_82 = V_14;
		IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910* L_83 = V_19;
		NullCheck(L_83);
		String_t* L_84;
		L_84 = VirtualFuncInvoker0< String_t* >::Invoke(5 /* System.String System.Exception::get_Message() */, L_83);
		String_t* L_85;
		L_85 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF1F4EE83F4EF40DB53192A2B50D97E241E77A4EB)), L_84, NULL);
		NullCheck(L_82);
		Directory_AddError_mCF615646756A385CAEA6E2CC4FE68D64F4021A71(L_82, L_85, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION();
		goto IL_0255;
	}// end catch (depth: 1)

IL_0205:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_86 = ___1_payload;
		ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F* L_87 = (ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F*)il2cpp_codegen_object_new(ByteArrayReader_t0CA6677CBB39193A16E60E9E4D8813C1DEA9066F_il2cpp_TypeInfo_var);
		NullCheck(L_87);
		ByteArrayReader__ctor_m9B95597991A73017EF2CEC40CAB69A560A89D137(L_87, L_86, 0, (bool)1, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_88 = ___1_payload;
		NullCheck(L_88);
		Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_89;
		L_89 = Encoding_get_ASCII_mCC61B512D320FD4E2E71CC0DFDF8DDF3CD215C65(NULL);
		NullCheck(L_87);
		String_t* L_90;
		L_90 = IndexedReader_GetString_m19BC68FA09D5030ECA3155E3ADBE883EFD7603A3(L_87, 0, ((int32_t)(((RuntimeArray*)L_88)->max_length)), L_89, NULL);
		V_20 = L_90;
		String_t* L_91 = V_20;
		NullCheck(L_91);
		int32_t L_92;
		L_92 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_91, NULL);
		if ((!(((uint32_t)L_92) == ((uint32_t)((int32_t)26)))))
		{
			goto IL_0243;
		}
	}
	{
		String_t* L_93 = V_20;
		NullCheck(L_93);
		bool L_94;
		L_94 = String_EndsWith_m5E5D307CA6AEB7C08CE782B4693B19D07ADC9075(L_93, _stringLiteralEB408DDC4FA484E6BEFDF5954E56A2198C7A9FAB, 4, NULL);
		if (!L_94)
		{
			goto IL_0243;
		}
	}
	{
		String_t* L_95 = V_20;
		NullCheck(L_95);
		String_t* L_96;
		L_96 = String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE(L_95, 0, ((int32_t)24), NULL);
		V_20 = L_96;
	}

IL_0243:
	{
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_97;
		L_97 = AviRiffHandler_GetOrCreateAviDirectory_m31016FEEABEF8391074705CAFBBC5051EC4BCD74(__this, NULL);
		String_t* L_98 = V_20;
		NullCheck(L_97);
		VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_97, ((int32_t)320), L_98);
	}

IL_0255:
	{
		return;
	}
}
// System.Void MetadataExtractor.Formats.Avi.AviRiffHandler::AddError(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AviRiffHandler_AddError_mECBFD4C52AD85ACA826CAF200472158EFE8ADA4F (AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5* __this, String_t* ___0_errorMessage, const RuntimeMethod* method) 
{
	{
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_0;
		L_0 = AviRiffHandler_GetOrCreateAviDirectory_m31016FEEABEF8391074705CAFBBC5051EC4BCD74(__this, NULL);
		String_t* L_1 = ___0_errorMessage;
		NullCheck(L_0);
		Directory_AddError_mCF615646756A385CAEA6E2CC4FE68D64F4021A71(L_0, L_1, NULL);
		return;
	}
}
// MetadataExtractor.Formats.Avi.AviDirectory MetadataExtractor.Formats.Avi.AviRiffHandler::GetOrCreateAviDirectory()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* AviRiffHandler_GetOrCreateAviDirectory_m31016FEEABEF8391074705CAFBBC5051EC4BCD74 (AviRiffHandler_t1453118A9CF6C3868BC748B252FDF2F62BC537C5* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m8C01AC4C40198210118E5E169A4FA596142917A6_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_0 = __this->____directory_1;
		if (L_0)
		{
			goto IL_0024;
		}
	}
	{
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_1 = (AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2*)il2cpp_codegen_object_new(AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		AviDirectory__ctor_mF28DB3DD363CC3CE48EC1AEA8EE504CBDAE655A4(L_1, NULL);
		__this->____directory_1 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____directory_1), (void*)L_1);
		List_1_tA67D583DFB13DFC9C55B709471B0FB86DE3560C0* L_2 = __this->____directories_0;
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_3 = __this->____directory_1;
		NullCheck(L_2);
		List_1_Add_m8C01AC4C40198210118E5E169A4FA596142917A6_inline(L_2, L_3, List_1_Add_m8C01AC4C40198210118E5E169A4FA596142917A6_RuntimeMethod_var);
	}

IL_0024:
	{
		AviDirectory_t5602AB91A0E499B344E059314C739B81E09D3AC2* L_4 = __this->____directory_1;
		return L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MetadataExtractor.Formats.Adobe.AdobeJpegDescriptor::.ctor(MetadataExtractor.Formats.Adobe.AdobeJpegDirectory)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AdobeJpegDescriptor__ctor_mA8A8DB470DE70504A93AB0F0E05E9D7EBA1CB15D (AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA* __this, AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* ___0_directory, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TagDescriptor_1__ctor_m750C1E77A6F3FD3BEA349A0AE3CEF90B1E9E0038_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_0 = ___0_directory;
		TagDescriptor_1__ctor_m750C1E77A6F3FD3BEA349A0AE3CEF90B1E9E0038(__this, L_0, TagDescriptor_1__ctor_m750C1E77A6F3FD3BEA349A0AE3CEF90B1E9E0038_RuntimeMethod_var);
		return;
	}
}
// System.String MetadataExtractor.Formats.Adobe.AdobeJpegDescriptor::GetDescription(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AdobeJpegDescriptor_GetDescription_m243E6596DECD1AAD5978FABC5050623F1097B330 (AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA* __this, int32_t ___0_tagType, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TagDescriptor_1_GetDescription_m2A08293E7212E61FB0ED1942A5196EAED8678E3F_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		int32_t L_0 = ___0_tagType;
		if (!L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1 = ___0_tagType;
		if ((!(((uint32_t)L_1) == ((uint32_t)3))))
		{
			goto IL_0019;
		}
	}
	{
		String_t* L_2;
		L_2 = AdobeJpegDescriptor_GetColorTransformDescription_m0757DB296D04C5F6532A6DEAF8B7B7C0712135F2(__this, NULL);
		V_0 = L_2;
		goto IL_0021;
	}

IL_0010:
	{
		String_t* L_3;
		L_3 = AdobeJpegDescriptor_GetDctEncodeVersionDescription_mD5D67F79B4549CC8658FD583CBAA9CFBD78ED791(__this, NULL);
		V_0 = L_3;
		goto IL_0021;
	}

IL_0019:
	{
		int32_t L_4 = ___0_tagType;
		String_t* L_5;
		L_5 = TagDescriptor_1_GetDescription_m2A08293E7212E61FB0ED1942A5196EAED8678E3F(__this, L_4, TagDescriptor_1_GetDescription_m2A08293E7212E61FB0ED1942A5196EAED8678E3F_RuntimeMethod_var);
		V_0 = L_5;
	}

IL_0021:
	{
		String_t* L_6 = V_0;
		return L_6;
	}
}
// System.String MetadataExtractor.Formats.Adobe.AdobeJpegDescriptor::GetDctEncodeVersionDescription()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AdobeJpegDescriptor_GetDctEncodeVersionDescription_mD5D67F79B4549CC8658FD583CBAA9CFBD78ED791 (AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DirectoryExtensions_t2A0E3E30420855CA057298B18B2396625DDF5E1D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TagDescriptor_1_get_Directory_mA075B82F615F061F332E7840C307691A66C87329_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8FE94193A3EF39943F898714AC9062F7EBD96279);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_0;
		L_0 = TagDescriptor_1_get_Directory_mA075B82F615F061F332E7840C307691A66C87329_inline(__this, TagDescriptor_1_get_Directory_mA075B82F615F061F332E7840C307691A66C87329_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(DirectoryExtensions_t2A0E3E30420855CA057298B18B2396625DDF5E1D_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = DirectoryExtensions_TryGetInt32_mA630CA2333FB5523F5A7ACBBE927BF7798BAA6EB(L_0, 0, (&V_0), NULL);
		if (L_1)
		{
			goto IL_0012;
		}
	}
	{
		return (String_t*)NULL;
	}

IL_0012:
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)((int32_t)100))))
		{
			goto IL_001f;
		}
	}
	{
		String_t* L_3;
		L_3 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		return L_3;
	}

IL_001f:
	{
		return _stringLiteral8FE94193A3EF39943F898714AC9062F7EBD96279;
	}
}
// System.String MetadataExtractor.Formats.Adobe.AdobeJpegDescriptor::GetColorTransformDescription()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AdobeJpegDescriptor_GetColorTransformDescription_m0757DB296D04C5F6532A6DEAF8B7B7C0712135F2 (AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TagDescriptor_1_GetIndexedDescription_m3C183A03543A77AA047617C6C238F92C8A939D83_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA00F72EF07EA85C3BAF99CB22C2C280A69C46BC1);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB0A138833DBD8A7FE850184B283B6396492468D0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFDEA9EABBBF0EEFF81C2958C4C87A3E791E08FEA);
		s_Il2CppMethodInitialized = true;
	}
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)3);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_1 = L_0;
		NullCheck(L_1);
		ArrayElementTypeCheck (L_1, _stringLiteralA00F72EF07EA85C3BAF99CB22C2C280A69C46BC1);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralA00F72EF07EA85C3BAF99CB22C2C280A69C46BC1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_2 = L_1;
		NullCheck(L_2);
		ArrayElementTypeCheck (L_2, _stringLiteralB0A138833DBD8A7FE850184B283B6396492468D0);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(1), (String_t*)_stringLiteralB0A138833DBD8A7FE850184B283B6396492468D0);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_3 = L_2;
		NullCheck(L_3);
		ArrayElementTypeCheck (L_3, _stringLiteralFDEA9EABBBF0EEFF81C2958C4C87A3E791E08FEA);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)_stringLiteralFDEA9EABBBF0EEFF81C2958C4C87A3E791E08FEA);
		String_t* L_4;
		L_4 = TagDescriptor_1_GetIndexedDescription_m3C183A03543A77AA047617C6C238F92C8A939D83(__this, 3, L_3, TagDescriptor_1_GetIndexedDescription_m3C183A03543A77AA047617C6C238F92C8A939D83_RuntimeMethod_var);
		return L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MetadataExtractor.Formats.Adobe.AdobeJpegDirectory::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AdobeJpegDirectory__ctor_m4BEE34709439DFD358A2ADB76E0757F9B61218D7 (AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_il2cpp_TypeInfo_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_0 = ((AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_StaticFields*)il2cpp_codegen_static_fields_for(AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_il2cpp_TypeInfo_var))->____tagNameMap_11;
		il2cpp_codegen_runtime_class_init_inline(Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A_il2cpp_TypeInfo_var);
		Directory__ctor_mD2BF152CC7614DEA9399A677108666AF34DCA483(__this, L_0, NULL);
		AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA* L_1 = (AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA*)il2cpp_codegen_object_new(AdobeJpegDescriptor_tB0805A4827871DA099C4BB0ED5C7A191C80E09BA_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		AdobeJpegDescriptor__ctor_mA8A8DB470DE70504A93AB0F0E05E9D7EBA1CB15D(L_1, __this, NULL);
		Directory_SetDescriptor_m9132B7EE403E6B6BF84E42AB6EBEFA7F49C8D1C2(__this, L_1, NULL);
		return;
	}
}
// System.String MetadataExtractor.Formats.Adobe.AdobeJpegDirectory::get_Name()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AdobeJpegDirectory_get_Name_m4A021F1532DD92E2124C607CDB7670023377FA45 (AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF657A368792D4A12C0CB5C93FDF095A8F3C96653);
		s_Il2CppMethodInitialized = true;
	}
	{
		return _stringLiteralF657A368792D4A12C0CB5C93FDF095A8F3C96653;
	}
}
// System.Void MetadataExtractor.Formats.Adobe.AdobeJpegDirectory::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AdobeJpegDirectory__cctor_m44A757B879878765C51E37A5A4201914F2BEF783 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mC854597C0C338BBA12EE451456D8658DF6D01BD4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0ED6B34E76D21901E1C28D2BBF5CB55189434E91);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2126DFC852A96E6C3DA999CD42496F1B088AC913);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB467A7760289D7B8EFDBF49D0ED022BFDA84240E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE738E8A8D805659811C98E0A2B2E7A9C24ACF9D1);
		s_Il2CppMethodInitialized = true;
	}
	{
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_0 = (Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9*)il2cpp_codegen_object_new(Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mC854597C0C338BBA12EE451456D8658DF6D01BD4(L_0, Dictionary_2__ctor_mC854597C0C338BBA12EE451456D8658DF6D01BD4_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_1 = L_0;
		NullCheck(L_1);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_1, 0, _stringLiteral2126DFC852A96E6C3DA999CD42496F1B088AC913, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_2 = L_1;
		NullCheck(L_2);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_2, 1, _stringLiteralB467A7760289D7B8EFDBF49D0ED022BFDA84240E, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_3 = L_2;
		NullCheck(L_3);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_3, 2, _stringLiteral0ED6B34E76D21901E1C28D2BBF5CB55189434E91, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		Dictionary_2_t291007AFA4B4075BA87D802F2E42017CB8C857C9* L_4 = L_3;
		NullCheck(L_4);
		Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128(L_4, 3, _stringLiteralE738E8A8D805659811C98E0A2B2E7A9C24ACF9D1, Dictionary_2_Add_m3531FBDB13EF62AAB20F8EB6598955DF14243128_RuntimeMethod_var);
		((AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_StaticFields*)il2cpp_codegen_static_fields_for(AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_il2cpp_TypeInfo_var))->____tagNameMap_11 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&((AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_StaticFields*)il2cpp_codegen_static_fields_for(AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_il2cpp_TypeInfo_var))->____tagNameMap_11), (void*)L_4);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Collections.Generic.ICollection`1<MetadataExtractor.Formats.Jpeg.JpegSegmentType> MetadataExtractor.Formats.Adobe.AdobeJpegReader::MetadataExtractor.Formats.Jpeg.IJpegSegmentMetadataReader.get_SegmentTypes()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* AdobeJpegReader_MetadataExtractor_Formats_Jpeg_IJpegSegmentMetadataReader_get_SegmentTypes_m16C3CE2A245854BC5F89CDFC0D9BA9A0A0BB9282 (AdobeJpegReader_t56227C3FB644AA11F0432D3331E7C5AB9872FBE5* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CMetadataExtractor_Formats_Jpeg_IJpegSegmentMetadataReader_SegmentTypesU3Ek__BackingField_1;
		return L_0;
	}
}
// System.Collections.Generic.IEnumerable`1<MetadataExtractor.Directory> MetadataExtractor.Formats.Adobe.AdobeJpegReader::ReadJpegSegments(System.Collections.Generic.IEnumerable`1<MetadataExtractor.Formats.Jpeg.JpegSegment>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* AdobeJpegReader_ReadJpegSegments_m77020044DD422212DA5092AFCF47AF7299376332 (AdobeJpegReader_t56227C3FB644AA11F0432D3331E7C5AB9872FBE5* __this, RuntimeObject* ___0_segments, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AdobeJpegReader_U3CReadJpegSegmentsU3Eb__4_1_m9B26E13582B739ECBBEAD4CBF6DF57EAE2C4C530_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_Select_TisJpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF_TisDirectory_t3179A156C81D90563D22A0D009C0821CE27FA51A_m4DC39D0F277FD093C793D8677DAF1293E6C334C8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_Where_TisJpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF_m0B083B7D77A38F867CF69AFB17AB8E091FEA8902_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Func_2_t679C7E0EDC405525B5A0DB02A53918AA6DD25D08_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_U3CReadJpegSegmentsU3Eb__4_0_m7DDEF62C7E5DFEA9CB46063AF916624971B9644F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E* G_B2_0 = NULL;
	RuntimeObject* G_B2_1 = NULL;
	Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E* G_B1_0 = NULL;
	RuntimeObject* G_B1_1 = NULL;
	{
		RuntimeObject* L_0 = ___0_segments;
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var);
		Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E* L_1 = ((U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var))->___U3CU3E9__4_0_1;
		Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E* L_2 = L_1;
		G_B1_0 = L_2;
		G_B1_1 = L_0;
		if (L_2)
		{
			G_B2_0 = L_2;
			G_B2_1 = L_0;
			goto IL_0020;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var);
		U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53* L_3 = ((U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var))->___U3CU3E9_0;
		Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E* L_4 = (Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E*)il2cpp_codegen_object_new(Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		Func_2__ctor_mAF6AF8B571A496F929570EA9A21B7E57C7D58995(L_4, L_3, (intptr_t)((void*)U3CU3Ec_U3CReadJpegSegmentsU3Eb__4_0_m7DDEF62C7E5DFEA9CB46063AF916624971B9644F_RuntimeMethod_var), NULL);
		Func_2_t64B5BC206E05A7F727D444947A2A72AB81B2B91E* L_5 = L_4;
		((U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var))->___U3CU3E9__4_0_1 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var))->___U3CU3E9__4_0_1), (void*)L_5);
		G_B2_0 = L_5;
		G_B2_1 = G_B1_1;
	}

IL_0020:
	{
		RuntimeObject* L_6;
		L_6 = Enumerable_Where_TisJpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF_m0B083B7D77A38F867CF69AFB17AB8E091FEA8902(G_B2_1, G_B2_0, Enumerable_Where_TisJpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF_m0B083B7D77A38F867CF69AFB17AB8E091FEA8902_RuntimeMethod_var);
		Func_2_t679C7E0EDC405525B5A0DB02A53918AA6DD25D08* L_7 = (Func_2_t679C7E0EDC405525B5A0DB02A53918AA6DD25D08*)il2cpp_codegen_object_new(Func_2_t679C7E0EDC405525B5A0DB02A53918AA6DD25D08_il2cpp_TypeInfo_var);
		NullCheck(L_7);
		Func_2__ctor_m3D81874EE3BDF42CA1D8E39EAD8F37A634268B49(L_7, __this, (intptr_t)((void*)AdobeJpegReader_U3CReadJpegSegmentsU3Eb__4_1_m9B26E13582B739ECBBEAD4CBF6DF57EAE2C4C530_RuntimeMethod_var), NULL);
		RuntimeObject* L_8;
		L_8 = Enumerable_Select_TisJpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF_TisDirectory_t3179A156C81D90563D22A0D009C0821CE27FA51A_m4DC39D0F277FD093C793D8677DAF1293E6C334C8(L_6, L_7, Enumerable_Select_TisJpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF_TisDirectory_t3179A156C81D90563D22A0D009C0821CE27FA51A_m4DC39D0F277FD093C793D8677DAF1293E6C334C8_RuntimeMethod_var);
		return L_8;
	}
}
// MetadataExtractor.Formats.Adobe.AdobeJpegDirectory MetadataExtractor.Formats.Adobe.AdobeJpegReader::Extract(MetadataExtractor.IO.SequentialReader)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* AdobeJpegReader_Extract_m45C3F2449ADA365EEFB5B469A89346094E6AE0BE (AdobeJpegReader_t56227C3FB644AA11F0432D3331E7C5AB9872FBE5* __this, SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* ___0_reader, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralAD298E5344B7CC8B91C66A36A7F003ABA7B7538B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE3643A741AC27679DCBEE196E29D8FDAACE03A2D);
		s_Il2CppMethodInitialized = true;
	}
	AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* V_0 = NULL;
	AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* V_1 = NULL;
	IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910* V_2 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* L_0 = ___0_reader;
		NullCheck(L_0);
		SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* L_1;
		L_1 = VirtualFuncInvoker1< SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01*, bool >::Invoke(5 /* MetadataExtractor.IO.SequentialReader MetadataExtractor.IO.SequentialReader::WithByteOrder(System.Boolean) */, L_0, (bool)0);
		___0_reader = L_1;
		AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_2 = (AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0*)il2cpp_codegen_object_new(AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		AdobeJpegDirectory__ctor_m4BEE34709439DFD358A2ADB76E0757F9B61218D7(L_2, NULL);
		V_0 = L_2;
	}
	try
	{// begin try (depth: 1)
		{
			SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* L_3 = ___0_reader;
			NullCheck(_stringLiteralE3643A741AC27679DCBEE196E29D8FDAACE03A2D);
			int32_t L_4;
			L_4 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(_stringLiteralE3643A741AC27679DCBEE196E29D8FDAACE03A2D, NULL);
			Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_5;
			L_5 = Encoding_get_ASCII_mCC61B512D320FD4E2E71CC0DFDF8DDF3CD215C65(NULL);
			NullCheck(L_3);
			String_t* L_6;
			L_6 = SequentialReader_GetString_m4A751A777A3358AB16636345345F373627952B75(L_3, L_4, L_5, NULL);
			bool L_7;
			L_7 = String_op_Inequality_m8C940F3CFC42866709D7CA931B3D77B4BE94BCB6(L_6, _stringLiteralE3643A741AC27679DCBEE196E29D8FDAACE03A2D, NULL);
			if (!L_7)
			{
				goto IL_003f_1;
			}
		}
		{
			AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_8 = V_0;
			NullCheck(L_8);
			Directory_AddError_mCF615646756A385CAEA6E2CC4FE68D64F4021A71(L_8, _stringLiteralAD298E5344B7CC8B91C66A36A7F003ABA7B7538B, NULL);
			AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_9 = V_0;
			V_1 = L_9;
			goto IL_00a4;
		}

IL_003f_1:
		{
			AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_10 = V_0;
			SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* L_11 = ___0_reader;
			NullCheck(L_11);
			uint16_t L_12;
			L_12 = SequentialReader_GetUInt16_mD37475AB2EA4490FDD658E33790E36718FEFF36A(L_11, NULL);
			uint16_t L_13 = L_12;
			RuntimeObject* L_14 = Box(UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var, &L_13);
			NullCheck(L_10);
			VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_10, 0, L_14);
			AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_15 = V_0;
			SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* L_16 = ___0_reader;
			NullCheck(L_16);
			uint16_t L_17;
			L_17 = SequentialReader_GetUInt16_mD37475AB2EA4490FDD658E33790E36718FEFF36A(L_16, NULL);
			uint16_t L_18 = L_17;
			RuntimeObject* L_19 = Box(UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var, &L_18);
			NullCheck(L_15);
			VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_15, 1, L_19);
			AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_20 = V_0;
			SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* L_21 = ___0_reader;
			NullCheck(L_21);
			uint16_t L_22;
			L_22 = SequentialReader_GetUInt16_mD37475AB2EA4490FDD658E33790E36718FEFF36A(L_21, NULL);
			uint16_t L_23 = L_22;
			RuntimeObject* L_24 = Box(UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var, &L_23);
			NullCheck(L_20);
			VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_20, 2, L_24);
			AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_25 = V_0;
			SequentialReader_tA4E5E28B238CA7F1472EAE4F43438C159FDACE01* L_26 = ___0_reader;
			NullCheck(L_26);
			int8_t L_27;
			L_27 = SequentialReader_GetSByte_m4AAD5E3C161C8E3056EB1399701A1759549255F2(L_26, NULL);
			int8_t L_28 = L_27;
			RuntimeObject* L_29 = Box(SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var, &L_28);
			NullCheck(L_25);
			VirtualActionInvoker2< int32_t, RuntimeObject* >::Invoke(6 /* System.Void MetadataExtractor.Directory::Set(System.Int32,System.Object) */, L_25, 3, L_29);
			goto IL_00a2;
		}
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0089;
		}
		throw e;
	}

CATCH_0089:
	{// begin catch(System.IO.IOException)
		V_2 = ((IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910*)IL2CPP_GET_ACTIVE_EXCEPTION(IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910*));
		AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_30 = V_0;
		IOException_t5D599190B003D41D45D4839A9B6B9AB53A755910* L_31 = V_2;
		NullCheck(L_31);
		String_t* L_32;
		L_32 = VirtualFuncInvoker0< String_t* >::Invoke(5 /* System.String System.Exception::get_Message() */, L_31);
		String_t* L_33;
		L_33 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral0008402531FBD99F266E5EAFCB7BB9B756EF702D)), L_32, NULL);
		NullCheck(L_30);
		Directory_AddError_mCF615646756A385CAEA6E2CC4FE68D64F4021A71(L_30, L_33, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION();
		goto IL_00a2;
	}// end catch (depth: 1)

IL_00a2:
	{
		AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_34 = V_0;
		return L_34;
	}

IL_00a4:
	{
		AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_35 = V_1;
		return L_35;
	}
}
// System.Void MetadataExtractor.Formats.Adobe.AdobeJpegReader::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AdobeJpegReader__ctor_mF2A64891AE96EAAEA272301863006A4158E5BD99 (AdobeJpegReader_t56227C3FB644AA11F0432D3331E7C5AB9872FBE5* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&JpegSegmentTypeU5BU5D_t84EA1C1277027054474CD7AF7079DB6B06020C4E_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		JpegSegmentTypeU5BU5D_t84EA1C1277027054474CD7AF7079DB6B06020C4E* L_0 = (JpegSegmentTypeU5BU5D_t84EA1C1277027054474CD7AF7079DB6B06020C4E*)(JpegSegmentTypeU5BU5D_t84EA1C1277027054474CD7AF7079DB6B06020C4E*)SZArrayNew(JpegSegmentTypeU5BU5D_t84EA1C1277027054474CD7AF7079DB6B06020C4E_il2cpp_TypeInfo_var, (uint32_t)1);
		JpegSegmentTypeU5BU5D_t84EA1C1277027054474CD7AF7079DB6B06020C4E* L_1 = L_0;
		NullCheck(L_1);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(0), (uint8_t)((int32_t)238));
		__this->___U3CMetadataExtractor_Formats_Jpeg_IJpegSegmentMetadataReader_SegmentTypesU3Ek__BackingField_1 = (RuntimeObject*)L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CMetadataExtractor_Formats_Jpeg_IJpegSegmentMetadataReader_SegmentTypesU3Ek__BackingField_1), (void*)(RuntimeObject*)L_1);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// MetadataExtractor.Directory MetadataExtractor.Formats.Adobe.AdobeJpegReader::<ReadJpegSegments>b__4_1(MetadataExtractor.Formats.Jpeg.JpegSegment)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Directory_t3179A156C81D90563D22A0D009C0821CE27FA51A* AdobeJpegReader_U3CReadJpegSegmentsU3Eb__4_1_m9B26E13582B739ECBBEAD4CBF6DF57EAE2C4C530 (AdobeJpegReader_t56227C3FB644AA11F0432D3331E7C5AB9872FBE5* __this, JpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF* ___0_bytes, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SequentialByteArrayReader_t56E08F41E026F2B557D64F7199F9A5FBFE7D7829_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		JpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF* L_0 = ___0_bytes;
		NullCheck(L_0);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1;
		L_1 = JpegSegment_get_Bytes_m50D5327094CC55158C7A61B0DD5045020AB48638_inline(L_0, NULL);
		SequentialByteArrayReader_t56E08F41E026F2B557D64F7199F9A5FBFE7D7829* L_2 = (SequentialByteArrayReader_t56E08F41E026F2B557D64F7199F9A5FBFE7D7829*)il2cpp_codegen_object_new(SequentialByteArrayReader_t56E08F41E026F2B557D64F7199F9A5FBFE7D7829_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		SequentialByteArrayReader__ctor_m886E431061EFEA9CD76547C61DDFC0AA9B6E7654(L_2, L_1, 0, (bool)1, NULL);
		AdobeJpegDirectory_t20113B051D702B0DFE4C203C0ECE802237BF08F0* L_3;
		L_3 = AdobeJpegReader_Extract_m45C3F2449ADA365EEFB5B469A89346094E6AE0BE(__this, L_2, NULL);
		return L_3;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MetadataExtractor.Formats.Adobe.AdobeJpegReader/<>c::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__cctor_mB1A7779C11652A4EE0177F0EC94636BF94F66F02 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53* L_0 = (U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53*)il2cpp_codegen_object_new(U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CU3Ec__ctor_mDF20E74AAA720E9D19B50A9B48E409BD93F2BA95(L_0, NULL);
		((U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var))->___U3CU3E9_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53_il2cpp_TypeInfo_var))->___U3CU3E9_0), (void*)L_0);
		return;
	}
}
// System.Void MetadataExtractor.Formats.Adobe.AdobeJpegReader/<>c::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_mDF20E74AAA720E9D19B50A9B48E409BD93F2BA95 (U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// System.Boolean MetadataExtractor.Formats.Adobe.AdobeJpegReader/<>c::<ReadJpegSegments>b__4_0(MetadataExtractor.Formats.Jpeg.JpegSegment)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CU3Ec_U3CReadJpegSegmentsU3Eb__4_0_m7DDEF62C7E5DFEA9CB46063AF916624971B9644F (U3CU3Ec_tA5D7AA63DF24128878C3B5763F6545A0BF7BFA53* __this, JpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF* ___0_segment, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE3643A741AC27679DCBEE196E29D8FDAACE03A2D);
		s_Il2CppMethodInitialized = true;
	}
	{
		JpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF* L_0 = ___0_segment;
		NullCheck(L_0);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1;
		L_1 = JpegSegment_get_Bytes_m50D5327094CC55158C7A61B0DD5045020AB48638_inline(L_0, NULL);
		NullCheck(L_1);
		if ((!(((uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))) == ((uint32_t)((int32_t)12)))))
		{
			goto IL_0033;
		}
	}
	{
		Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_2;
		L_2 = Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9(NULL);
		JpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF* L_3 = ___0_segment;
		NullCheck(L_3);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4;
		L_4 = JpegSegment_get_Bytes_m50D5327094CC55158C7A61B0DD5045020AB48638_inline(L_3, NULL);
		NullCheck(_stringLiteralE3643A741AC27679DCBEE196E29D8FDAACE03A2D);
		int32_t L_5;
		L_5 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(_stringLiteralE3643A741AC27679DCBEE196E29D8FDAACE03A2D, NULL);
		NullCheck(L_2);
		String_t* L_6;
		L_6 = VirtualFuncInvoker3< String_t*, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, int32_t, int32_t >::Invoke(36 /* System.String System.Text.Encoding::GetString(System.Byte[],System.Int32,System.Int32) */, L_2, L_4, 0, L_5);
		NullCheck(_stringLiteralE3643A741AC27679DCBEE196E29D8FDAACE03A2D);
		bool L_7;
		L_7 = String_Equals_m7BDFC0B951005B9DC2BAED464AFE68FF7E9ACE5A(_stringLiteralE3643A741AC27679DCBEE196E29D8FDAACE03A2D, L_6, 5, NULL);
		return L_7;
	}

IL_0033:
	{
		return (bool)0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t TimeSpan_get_Ticks_mC50131E57621F29FACC53B3241432ABB874FA1B5_inline (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A* __this, const RuntimeMethod* method) 
{
	{
		int64_t L_0 = __this->____ticks_22;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____stringLength_4;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* JpegSegment_get_Bytes_m50D5327094CC55158C7A61B0DD5045020AB48638_inline (JpegSegment_tED45D896AC0938ECA76B3274E6F565CE33CB7AAF* __this, const RuntimeMethod* method) 
{
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->___U3CBytesU3Ek__BackingField_1;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* TagDescriptor_1_get_Directory_mAA3224DFCA53F7D6E690D426554A10AA3DD928E9_gshared_inline (TagDescriptor_1_t54DDB11CF6366D35183686BA442DEBB16FF64390* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CDirectoryU3Ek__BackingField_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version_3;
		__this->____version_3 = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = __this->____items_1;
		V_0 = L_1;
		int32_t L_2 = __this->____size_2;
		V_1 = L_2;
		int32_t L_3 = V_1;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_6 = V_0;
		int32_t L_7 = V_1;
		RuntimeObject* L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (RuntimeObject*)L_8);
		return;
	}

IL_0034:
	{
		RuntimeObject* L_9 = ___0_item;
		((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 11)))(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		return;
	}
}
