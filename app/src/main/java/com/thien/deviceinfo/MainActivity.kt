package com.thien.deviceinfo

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.thien.deviceinfo.adapter.MainScreenAdapter


class MainActivity : AppCompatActivity() {
    lateinit var list: RecyclerView
    var name = arrayOf(
        "Device",
        "Model",
        "Device ID",
        "SDK",
        "Security Patch",
        "Android Version",
        "Base Os", "Build Number",
        "Brand",
        "FingerPrint",
        "Hardware",
        "Host",
        "Manufacture",
        "Product",
        "BootLoader"
    )
    var test = arrayOf(
        getDevice(),
        getModel(),
        getID(),
        getSdk().toString(),
        getSecurityPatch(),
        getAndroidVersion(),
        getBaseOs(),
        getBuildNumber(),
        getBrand(),
        getFP(),
        getHardware(),
        getHost(),
        getManufacture(),
        getProduct(),
        getBootloader(),
    )


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        list = findViewById(R.id.listRecyclerView)
        list.layoutManager = LinearLayoutManager(this)
        list.adapter = MainScreenAdapter(name, test)
        Log.i("Android ID :", getAndroidID())
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
//    external fun getMacAddress() : String
    private external fun getModel(): String
    private external fun getDevice(): String
    private external fun getSdk(): Int
    private external fun getSecurityPatch(): String
    private external fun getAndroidVersion(): String
    private external fun getBaseOs(): String
    private external fun getBuildNumber(): String
    private external fun getID(): String
    private external fun getBootloader(): String
    private external fun getBrand(): String
    private external fun getFP(): String
    private external fun getHardware(): String
    private external fun getHost(): String
    private external fun getManufacture(): String
    private external fun getProduct(): String
    private external fun getMac(): String
    private external fun testCheckPerm(): Boolean
    private external fun getAndroidID(): String
//    private external fun getSerial(): String


    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}