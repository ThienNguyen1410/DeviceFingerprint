package com.thien.deviceinfo.adapter

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.thien.deviceinfo.R

class MainScreenAdapter(
    private val nameResource: Array<String>,
    private val dataSet: Array<String>
) : RecyclerView.Adapter<MainScreenAdapter.ViewHolder>() {

    class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val num: TextView = view.findViewById(R.id.text1)
        val nameResource: TextView = view.findViewById(R.id.text2)
        val data: TextView = view.findViewById(R.id.text3)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.dfp, parent, false)
        return ViewHolder(view)
    }

    override fun getItemCount(): Int {
        return dataSet.size
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        holder.num.text = (position + 1).toString()
        holder.nameResource.text = nameResource[position]
        holder.data.text = dataSet[position]
    }
}