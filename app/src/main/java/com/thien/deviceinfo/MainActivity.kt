package com.thien.deviceinfo

import android.content.Context
import android.net.wifi.WifiManager
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.thien.deviceinfo.R
import com.thien.deviceinfo.adapter.MainScreenAdapter


class MainActivity : AppCompatActivity() {
    lateinit var list : RecyclerView
    var name = arrayOf("Device","Model","SDK","Security Patch","Android Version","Incremental","Base Os","Screen")
    var test = arrayOf(getBrand(),
        getModel(),
        getSdk().toString(),
        getSecurityPatch(),
        getAndroidVersion(),
        getBaseOs(),
        getBuildNumber()
    )


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        list = findViewById(R.id.listRecyclerView)
        list.layoutManager = LinearLayoutManager(this)
        list.adapter = MainScreenAdapter(name,test);
    }



    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
//    external fun getMacAddress() : String
    private external fun getModel() : String
    private external fun getBrand() : String
    private external fun getSdk() : Int
    private external fun getSecurityPatch():String
    private external fun getAndroidVersion() : String
    private external fun getBaseOs():String
    private external fun getBuildNumber():String
    private external fun testmac():String


    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}