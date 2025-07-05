package com.example.cafeoverflow.Adapter;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.core.content.ContextCompat;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;
import com.example.cafeoverflow.Activity.RecyclerViewProductsInterface;
import com.example.cafeoverflow.Domain.ProductDomain;
import com.example.cafeoverflow.R;

import java.util.ArrayList;

public class ProductAdapt extends RecyclerView.Adapter<ProductAdapt.ViewHolder> {
    ArrayList<ProductDomain>productDomains;

    private final RecyclerViewProductsInterface recyclerViewProductsInterface;

    public ProductAdapt(ArrayList<ProductDomain> productDomains, RecyclerViewProductsInterface recyclerViewProductsInterface) {
        this.productDomains = productDomains;
        this.recyclerViewProductsInterface = recyclerViewProductsInterface;
    }

    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View inflate = LayoutInflater.from(parent.getContext()).inflate(R.layout.viewholder_product,parent,false);
        return new ViewHolder(inflate, recyclerViewProductsInterface);
    }

    @Override
    public void onBindViewHolder(@NonNull ProductAdapt.ViewHolder holder, int position) {
        holder.productName.setText(productDomains.get(position).getProductName());
        String picUrl = "";
        switch (position){
            case 0:{
                picUrl="banner_coffee";
                holder.mainLayout.setBackground(ContextCompat.getDrawable(holder.itemView.getContext(),R.drawable.product_background));
                break;
            }
            case 1:{
                picUrl="banner_coffee";
                holder.mainLayout.setBackground(ContextCompat.getDrawable(holder.itemView.getContext(),R.drawable.product_background));
                break;
            }
            case 2:{
                picUrl="banner_coffee";
                holder.mainLayout.setBackground(ContextCompat.getDrawable(holder.itemView.getContext(),R.drawable.product_background));
                break;
            }
            case 3:{
                picUrl="banner_coffee";
                holder.mainLayout.setBackground(ContextCompat.getDrawable(holder.itemView.getContext(),R.drawable.product_background));
                break;
            }
            case 4:{
                picUrl="banner_coffee";
                holder.mainLayout.setBackground(ContextCompat.getDrawable(holder.itemView.getContext(),R.drawable.product_background));
                break;
            }
        }
        int drawableResourceId=holder.itemView.getContext().getResources().getIdentifier(picUrl,"drawable",holder.itemView.getContext().getPackageName());

        Glide.with(holder.itemView.getContext())
                .load(drawableResourceId)
                .into(holder.productPic);
    }

    @Override
    public int getItemCount() {

        return productDomains.size();
    }

    public static class ViewHolder extends RecyclerView.ViewHolder {
        TextView productName;
        ImageView productPic;
        ConstraintLayout mainLayout;

        public ViewHolder(@NonNull View itemView, RecyclerViewProductsInterface recyclerViewProductsInterface){
            super(itemView);
            productName=itemView.findViewById(R.id.productName);
            productPic=itemView.findViewById(R.id.productPic);
            mainLayout=itemView.findViewById(R.id.mainLayout);

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    if (recyclerViewProductsInterface != null){
                        int pos = getAdapterPosition();

                        if (pos != RecyclerView.NO_POSITION){
                            recyclerViewProductsInterface.onProductClick(pos);
                        }
                    }
                }
            });
        }
    }
}
