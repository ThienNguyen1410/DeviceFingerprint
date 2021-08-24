package com.thien.deviceinfo

import android.content.pm.PackageInfo
import android.os.Build
import android.os.Bundle
import android.util.Log
import androidx.annotation.RequiresApi
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.thien.deviceinfo.adapter.MainScreenAdapter
import java.security.Provider
import java.util.*


class MainActivity : AppCompatActivity() {
    lateinit var list: RecyclerView
    var name = mutableListOf<String>(
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
        "BootLoader",
        "AndroidID",
        "Battery Percent",
        "SimSerial",
        "SimState",
        "User",
        "Ip",
        "Mac Address",
        "Date and Time",
    )
    var test = mutableListOf<String>(
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


    @RequiresApi(Build.VERSION_CODES.LOLLIPOP)
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        list = findViewById(R.id.listRecyclerView)
        list.layoutManager = LinearLayoutManager(this)
//        val REQUEST_CODE = 1
//        ActivityCompat.requestPermissions(this,
//            arrayOf(android.Manifest.permission.ACCESS_FINE_LOCATION),
//            REQUEST_CODE)
        test.add(getAndroidID())
        test.add(batteryCapacity().toString())
        test.add(simSerial())
        test.add(user())
        test.add(getMac())
        test.add(getTime().toString())
//        test.add(longitude().toString())
//        test.add(latitude().toString())

        for (i in securityProvider()) {
            Log.i("Security Provider :  ", i.toString())
        }
        for (p in installedPackage()) {
            Log.i("Package installed : ", p.toString())
        }
        Log.i("Time : ", getTime().toString())

        list.adapter = MainScreenAdapter(name.toTypedArray(), test.toTypedArray())
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
    private external fun batteryCapacity(): Int
    private external fun simSerial(): String
    private external fun user(): String

    //    private external fun ip(): Int
    private external fun installedPackage(): ArrayList<PackageInfo>
    private external fun longitude(): Double
    private external fun latitude(): Double
    private external fun securityProvider(): kotlin.Array<Provider>
    private external fun isSecurityEncrypt(): Boolean
    private external fun getTime(): Date
    //private external fun locale() : Locale


    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}