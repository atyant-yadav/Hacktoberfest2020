//Simple sound class to modify and use your sound clips in Unity.


using UnityEngine.Audio;

using UnityEngine;
using System;

[System.Serializable]
public class Sound 
{
    public string name;
    public AudioClip clip;
    [Range(0f,1f)]
    public float volume;
    [Range(.1f,3f)]
    public float pitch;
    public Boolean loop;

    [HideInInspector]
    public AudioSource source;
}
