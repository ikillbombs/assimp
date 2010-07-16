/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class aiVectorKey : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal aiVectorKey(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(aiVectorKey obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~aiVectorKey() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          AssimpPINVOKE.delete_aiVectorKey(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  public double mTime {
    set {
      AssimpPINVOKE.aiVectorKey_mTime_set(swigCPtr, value);
    } 
    get {
      double ret = AssimpPINVOKE.aiVectorKey_mTime_get(swigCPtr);
      return ret;
    } 
  }

  public aiVector3D mValue {
    set {
      AssimpPINVOKE.aiVectorKey_mValue_set(swigCPtr, aiVector3D.getCPtr(value));
    } 
    get {
      IntPtr cPtr = AssimpPINVOKE.aiVectorKey_mValue_get(swigCPtr);
      aiVector3D ret = (cPtr == IntPtr.Zero) ? null : new aiVector3D(cPtr, false);
      return ret;
    } 
  }

  public aiVectorKey() : this(AssimpPINVOKE.new_aiVectorKey__SWIG_0(), true) {
  }

  public aiVectorKey(double time, aiVector3D value) : this(AssimpPINVOKE.new_aiVectorKey__SWIG_1(time, aiVector3D.getCPtr(value)), true) {
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public bool __equal__(aiVectorKey o) {
    bool ret = AssimpPINVOKE.aiVectorKey___equal__(swigCPtr, aiVectorKey.getCPtr(o));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool __nequal__(aiVectorKey o) {
    bool ret = AssimpPINVOKE.aiVectorKey___nequal__(swigCPtr, aiVectorKey.getCPtr(o));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool __smaller__(aiVectorKey o) {
    bool ret = AssimpPINVOKE.aiVectorKey___smaller__(swigCPtr, aiVectorKey.getCPtr(o));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool __greater__(aiVectorKey o) {
    bool ret = AssimpPINVOKE.aiVectorKey___greater__(swigCPtr, aiVectorKey.getCPtr(o));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}